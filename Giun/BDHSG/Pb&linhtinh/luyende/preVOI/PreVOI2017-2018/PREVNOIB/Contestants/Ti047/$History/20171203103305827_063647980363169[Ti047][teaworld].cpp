
//{
#ifdef _GLIBCXX_DEBUG
	#include <iostream>
#else
	#define NDEBUG
	#include <fstream>
	std::string const name = [](const std::string fullname)->std::string{
		size_t first = 1 + fullname.find_last_of( /* any of */ "/\\");
		size_t dot = fullname.find_first_of('.', first);
		return fullname.substr(first, dot - first);
	}(__FILE__); // calculate in runtime, unfortunately
	namespace std {
		std::ifstream cin ((::name + ".inp").c_str());
		std::ofstream cout ((::name + ".out").c_str());
	}
#endif //} _GLIBCXX_DEBUG

#include <vector>
#include <bitset>

template <typename T> static T sqr(T x){return x*x;}

template <typename T>
struct point3d { //{

	T x, y, z;
	point3d () : x(0), y(0), z(0) {}
	point3d (T x1, T y1, T z1) : x (x1), y (y1), z (z1) {};
	point3d operator +  (point3d a) const { return point3d(x+a.x, y+a.y, z+a.z); }
	point3d operator -  (point3d a) const { return point3d(x-a.x, y-a.y, z-a.z); }
	point3d operator -  (/*unary*/) const { return point3d(-x, -y, -z); }
	point3d&operator += (point3d a) { x += a.x; y += a.y; z += a.z; return *this; }
	point3d&operator -= (point3d a) { x -= a.x; y -= a.y; z -= a.z; return *this; }
	point3d operator *  (T a) const { return point3d(x*a, y*a, z*a); }
	point3d&operator *= (T a) { x *= a; y *= a; z *= a; return *this; }
	point3d operator *  (point3d a) const { return point3d(
		y * a.z - z * a.y,
		z * a.x - x * a.z,
		x * a.y - y * a.x
		);
	} // cross // no *= version of this

	T dot(point3d a) const { return x*a.x + y*a.y + z*a.z; }

	template <typename result_type = T>
	result_type norm() const { return x*result_type(x) + y*result_type(y) + z*result_type(z); }
	// norm may need more precision

//	template <typename /* anonymous */ = typename std::enable_if<std::is_floating_point<T>::value, T>::type>
//	T length() const { return std::sqrt(norm()); }
	bool operator ==(point3d<T> p) {return x==p.x && y==p.y && z==p.z;}
	bool operator !=(point3d<T> p) {return !(this->operator ==(p));}
};

template <typename T>
std::istream& operator >> (std::istream& str, point3d<T>& pt) {
	str >> pt.x >> pt.y >> pt.z;
	return str;
}

template <typename T>
std::ostream& operator << (std::ostream& str, point3d<T> const & pt) {
	#ifdef _GLIBCXX_DEBUG
	return str << "(" << pt.x << ", " << pt.y << ", " << pt.z << ")";
	#else
	return str;
	#endif // _GLIBCXX_DEBUG
}
//}

using pt = point3d<int>;

struct ball {
	pt center;
	int radius;
};

struct store {
	pt pos;
	int value;
};

// return [true] if the (closed) line segment {0, 0, 0} <-> [p] has any common point with
// the (closed) ball (sphere) [b].
bool conflict(ball const & b, pt const & p) {
	bool homeInsideBall = b.center.norm() <= sqr(b.radius);
	bool pInsideBall = (b.center - p).norm() <= sqr(b.radius);
	if (homeInsideBall != pInsideBall) return true;
	if (homeInsideBall && pInsideBall) return false;
	// now both are outside (false)
	/*
	[b]
	  .                          [b]
	    .                       .
		  .	                   .
	       [O]...............[p]
	*/ if (p.dot(b.center) <= 0 || (-p).dot(b.center-p) <= 0) return false;
		// dist [b] .. [OP] = dist [b] .. Line[OP] = p.cross(b) / p.length()
	return
//		b.radius >= p.cross(b) / (double)p.length()
//		sqr(b.radius) >= sqr(p.cross(b)) / p.norm()
		sqr(b.radius) * p.norm<long long>() >= (p * b.center).norm<long long>();
	;
}

// ----------- mask

using mask_t = std::bitset<2000>;

int main() {
	int mBall, nStore, kRemoveBall;
	std::cin >> mBall >> nStore >> kRemoveBall;
	std::vector<ball> balls (mBall); for (ball& b : balls) std::cin >> b.center >> b.radius;
	std::vector<store> stores (nStore); for (store& s : stores) std::cin >> s.pos >> s.value;
	pt home; std::cin >> home;

	for (ball& b : balls) b.center -= home;
	for (store& s : stores) s.pos -= home;
	home = {};

	std::vector<mask_t> mask (nStore);
	for (int st = 0; st < nStore; ++st) {
		for (int b = 0; b < mBall; ++b) {
			mask[st][b] = conflict(balls[b], stores[st].pos);
		}
		std::cerr << "store " << stores[st].pos << " conflict with " << mask[st].count() << " balls\n";
	}

	int ans = 0;
	for (unsigned store_mask = 1u << nStore; store_mask --> 0;) {
		mask_t m;
		for (int st = 0; st < nStore; ++st)
			if (store_mask & (1 << st)) m |= mask[st];

		if (m.count() <= kRemoveBall) {
			int sumValue = 0;
			for (int st = 0; st < nStore; ++st)
				if (store_mask & (1 << st)) sumValue += stores[st].value;
			ans = std::max(ans, sumValue);
		}
	}

	std::cout << ans << '\n';
}

/*

12 5 4

0 10 0 1
1 5 0 2
1 4 0 2
0 0 0 2
10 0 0 1
3 -1 0 2
5 -1 0 2
10 10 0 15
0 -10 0 1
10 -10 0 1
-10 -10 0 1
10 10 0 1

0 10 0 240
10 0 0 200
10 -2 0 52
-10 0 0 100
1 1 0 2

0 0 0

==> 254

*/
