import logging
from flask import Flask 

app = Flask(__name__)
#log = create_logger(app)
logging.basicConfig(level=logging.DEBUG)

@app.route('/')
def helloword():
    app.logger.info('test')
    return 'Hello!'


@app.route('/user/<name>')
def adminpage(name):
    return 'hello %s' % name


if __name__ == '__main__':
    app.logger.setLevel(logging.INFO)
    app.run(debug=True)

