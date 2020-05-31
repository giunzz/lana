from requests_html import HTMLSession
from urllib3.util import  parse_url

def checktile(s):

    return

def processUrl(link):
    urlSplit = parse_url(link)
    result = '{uri.scheme}://{uri.host}/'.format(uri=urlSplit)
    return result

session = HTMLSession()
urlL = 'http://www.phimmoi.net/phim/bac-si-thien-tai-phan-1-i9-6082/xem-phim.html'
urlHost = processUrl(urlL)
print(urlHost)
r = session.get(urlL)
rs = r.html.find('.list-episode a',first=False)
for x in rs:
    detail = x.attrs
    print(detail['href'])
    # exit()