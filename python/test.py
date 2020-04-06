import requests

url = 'https://www.hackthebox.eu/api/invite/generate'
myobj = {'somekey': 'somevalue'}

x = requests.post(url, data = myobj)

print(x.text)