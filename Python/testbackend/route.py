import sys, time
from flask import Flask, redirect, url_for 

# directfilelog = 'python/testbackend/f.log'
app = Flask(__name__)

@app.route('/')
def helloword():
    # with open(directfilelog, 'a') as log:
    #     current_time = time.strftime("%H:%M:%S", time.localtime())
    #     log.write(current_time + ' test log\n')
    return 'Hello!'
    
@app.route('/abc/dc')
def abc():
    # with open(directfilelog, 'a') as log:
    #     current_time = time.strftime("%H:%M:%S", time.localtime())
    #     log.write(current_time + ' test log\n')
    return 'abc'


@app.route('/user/<name>')
def adminpage(name):
    # with open(directfilelog, 'a') as log:
    #     log.write('test log 1\n')
    return 'hello %s' % name


@app.route('/quang')
def quang():
    return redirect(url_for('abc/dc'))

if __name__ == '__main__':
    # with open(directfilelog, 'w') as log:
    #     log.write('test log 2\n')
    app.run(debug=True)