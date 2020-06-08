import requests
sites = [
    'http://www.python.org',
    'http://www.jython.org',
    'http://www.pypy.org',
    'http://www.drudgereport.com',
    'http://www.phys.org',
    'http://www.bluegalaxy.info',
    'http://www.bluegalaxy.info/codewalk'
]
for url in sites:
    r = requests.get(url)
    page_source = r.text
    page_source = page_source.split('\n')
    print("\nURL:", url) 
    print("--------------------------------------")
    # print the first five lines of the page source
    for row in page_source[:5]:
        print(row)
    print("--------------------------------------")