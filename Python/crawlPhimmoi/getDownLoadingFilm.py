from requests_html import HTMLSession

def downloadFilm(UrlFilm, UrlRoot):
    session = HTMLSession()
    r = session.get(UrlFilm)
    rs = r.html.find('#btn-download', first=False)
    links = r.html.absolute_links
    for x in rs:
        print(x.attrs)


if __name__ == '__main__':
    downloadFilm('http://www.phimmoi.net/phim/bac-si-thien-tai-phan-1-i9-6082/xem-phim.html', 'http://www.phimmoi.net/')