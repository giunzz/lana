#include <windows.h>

const char* ClassName = "Win32 API from stdio.vn";

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// Bước 1: tạo một Window Class
	WNDCLASSEX wc; //wc = window class -> chứa tất cả thông tin của 1 window

	wc.cbSize = sizeof(WNDCLASSEX);	//kích thước trên bộ nhớ của window class này
	wc.style = 0;	//kiểu của Class, khác với kiểu của window (window style), thường có giá trị 0
	wc.lpfnWndProc = WndProc;	//thủ tục của window (window procedure) là con trỏ trỏ tới WinProc như ở trên (giải thích bên dưới, Bước 4)
	wc.cbClsExtra = 0;	//số lượng dữ liệu tối đa được cài đặt cho class này, thường có giá trị 0 (không cần quan tâm lắm, tìm hiểu sau)
	wc.cbWndExtra = 0;	//số lượng dữ liệu tối đa được cài đặt cho class này, thường có giá trị 0 (không cần quan tâm lắm, tìm hiểu sau)
	wc.hInstance = hInstance;	//Quản lý thông tin của cửa sổ, tương đương với giá trị ta khai báo ở WinMain() (tìm hiểu sau)
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);		//Icon lớn của class này, như đoạn code ở trên ta khai báo là icon có sẵn trong hệ thống, Icon này thẻ hiện ở (tìm hiểu sau)
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);	//tương tự như Icon nhưng ở đây là con trỏ
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);	//tương tự như icon nhưng là background
	wc.lpszMenuName = NULL;	//con trỏ trỏ về dữ liệu của các thanh menu (tìm hiểu sau)
	wc.lpszClassName = ClassName;	//tên của class này, như trên là ta cài đặt tên có sẵn khai báo ở đầu bài
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);	//tương tự như icon nhưng là icon nhỏ, hiện ở bên trái cùng chương trình

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Cannot Register window", "Error", MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	//Sau khi tạo xong một lớp cửa sổ (window class) thì ta có thể dùng nó để tạo 1 cửa sổ;

	HWND hwnd;
	hwnd = CreateWindowEx(	//Creating window: viết xuông dòng nhằm mục đích cho code dễ đọc
		WS_EX_CLIENTEDGE,	//Một kiểu mở rộng của "window style", có thể thay thế bằng giá trị 0 để xem sự khác biệt
		ClassName,	//Để hệ thống "hiểu rằng" ta đang đăng ký cửa sổ này cho class nào
		"The title of stdio.vn",	//Thanh tiêu đề (Title Bar or Caption)
		WS_OVERLAPPEDWINDOW,	//Một dạng "kiểu" của "window style" (tìm hiểu sau)
		CW_USEDEFAULT,	//Tọa độ X của "bên trái trên cùng" của window
		CW_USEDEFAULT,	//Tọa độ Y của "bên phải trên cùng"	của window

		//Cài đặt giá trị CW_USEDEFAULT để "Windows" chọn tọa độ cho ta, từ góc trái trên cùng, X là từ trái -> phải, Y là từ trên -> dưới, đơn vị là các pixels

		240,	//Chiều rộng (width)
		120,	//Chiều cao (height)
		NULL,	//Parent Window
		NULL,	//Menu handle
		hInstance,	//Application Instance handle
		NULL	//A pointer to window creation data
		);

	//Trong Windows, các cửa sổ (screen) chia ra làm các cấp bậc là "cha và con", nếu có 1 nút (button) trên 1 cửa sổ (window) thì button là con của window đó. Trong ví dụ trên vì đây là Cửa sổ trên cùng (Top level) nên các giá trị là NULL. trường "Application Instance handle" tương ứng với khai báo trên WinMain(), trường "A pointer to window creation data" con trỏ có thể dùng để gửi các thông tin bổ sung vào window này.

	//Luôn luôn kiểm tra lại các giá trị trả về (return values)

	if (hwnd == NULL)
	{
		MessageBox(NULL, "Window Creation Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);


	//Vòng lặp lệnh (Message Loop)
	// Mọi thứ trong chương trình của bạn đều phải chạy qua đây

	MSG Msg;

	while (GetMessage(&Msg, NULL, 0, 0) > 0)	//Lấy lệnh thực thi từ queue, bất cứ khi nào rê chuột, click hay gõ phím, ... đều được hệ thông ghi nhận và truyền đạt lại thành message, dùng hàm GetMessage() để lấy message kế tiếp thích hợp từ máy tính
	{
		TranslateMessage(&Msg);	//Dịch message (tìm hiểu sau)
		DispatchMessage(&Msg);	//Gửi message đến window
	}
	return Msg.wParam;


}

//Tiến trình Window (Window Procedure)

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)	//Là thủ tục được gọi tương ứng với mỗi message, nếu có 2 windows thì cả 2 windows này dùng chung 1 thủ tục (window procedure)
{
	switch (msg)
	{
		//Khi message là WM_CLOSE <=> Alt + F4 hoặc nút tắt (X) thì DestroyWindow() sẽ gửi lệnh WM_DESTROY vào hàng đợi message (queqe)

	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:	//Khi lệnh WM_DESTROY được gọi, nó sẽ xóa các "con" của cửa sổ này trước khi xóa hẳn nó trên hệ thống
		PostQuitMessage(0); //WM_QUIT vào hàng đợi message
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}


//#include <windows.h>
//
//const char* ClassName = "Win32 API form stdio.vn";
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//	WNDCLASSEX wc;
//	HWND hwnd;
//	MSG Msg;
//
//	// Bước 1: Đăng ký 1 window class
//	wc.cbSize = sizeof(WNDCLASSEX);
//	wc.style = 0;
//	wc.lpfnWndProc = WndProc;
//	wc.cbClsExtra = 0;
//	wc.cbWndExtra = 0;
//	wc.hInstance = hInstance;
//	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//	wc.lpszMenuName = NULL;
//	wc.lpszClassName = ClassName;
//	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
//
//	if (!RegisterClassEx(&wc))
//	{
//		MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
//		return 0;
//	}
//
//	// Bước 2: Tạo window
//	hwnd = CreateWindowEx(
//		WS_EX_CLIENTEDGE,
//		ClassName,
//		"The title of stdio.vn",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT,
//		CW_USEDEFAULT,
//		240,
//		120,
//		NULL,
//		NULL,
//		hInstance,
//		NULL
//		);
//
//	if (hwnd == NULL)
//	{
//		MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
//		return 0;
//	}
//
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//
//	// Bước 3: Vòng lặp Message
//	while (GetMessage(&Msg, NULL, 0, 0) > 0)
//	{
//		TranslateMessage(&Msg);
//		DispatchMessage(&Msg);
//	}
//	return Msg.wParam;
//}
//
//// Bước 4: Tạo thủ tục window
//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//	switch (msg)
//	{
//	case WM_CLOSE:
//		DestroyWindow(hwnd);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	default:
//		return DefWindowProc(hwnd, msg, wParam, lParam);
//	}
//	return 0;
//}
