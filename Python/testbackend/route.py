from flask import Flask

app = Flask(__name__)


@app.route('/')
def helloword():
    return 'Hello!'


@app.route('/user/<name>')
def adminpage(name):
    return 'hello %s' % name


if __name__ == '__main__':
    app.run()

