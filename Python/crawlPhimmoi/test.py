from requests_html import HTMLSession
from time import sleep

session = HTMLSession()
Url = 'http://pzc.phimmoi.net/embed/ab2e0a4aea21a263cc1964626654f138'
Urlf = 'http://www.phimmoi.net/phim/bac-si-thien-tai-phan-1-i9-6082/tap-1-146894.html'
q = session.get(Urlf)
sleep(10)
r = session.get(Url)
print(r)