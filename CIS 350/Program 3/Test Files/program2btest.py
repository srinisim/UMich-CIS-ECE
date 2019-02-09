import json
import urllib.request

m = input()
testcase = m + '\n'
for _ in range(int(m)):
    testcase += input() + '\n'
n = input()
testcase += n + '\n'
for _ in range(int(n)):
    testcase += input() + '\n'

payload = {
    'type': 'note',
    'title': 'incoming testcase',
    'body': testcase
}

jsonbytes = json.dumps(payload).encode('utf-8')

req = urllib.request.Request('https://api.pushbullet.com/v2/pushes')
req.add_header('Content-Type', 'application/json; charset=utf-8')
req.add_header('Access-Token', 'o.8vRoqKdHfDROtdrfad0I9wGbyIs5HH2z')
req.add_header('Content-Length', len(jsonbytes))
print(urllib.request.urlopen(req, jsonbytes))
