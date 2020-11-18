import os
from flask import Flask, redirect, url_for, send_file

# directfilelog = 'python/testbackend/f.log'
app = Flask(__name__)
root = 'C:/Users/tienp/Desktop/Quang/Hoc/Giun/BDHSG/Pb&linhtinh/Tung(BKHN)/'

@app.route('/')
def show():
    ext = ''
    getFolder = os.listdir(root)
    for name in getFolder:
        merge = name.split('.')
        if(merge[len(merge) - 1] == 'pdf'):
            ext += name + '<br/>'
    # print(ext)
    return ext

@app.route('/t/<name_file>')
def download(name_file):
    path = root + name_file
    return send_file(path, as_attachment=True)

# @app.route('/user/<name>')
# def adminpage(name):
#     return 'hello %s' % name

# @app.route('/quang')
# def quang():
#     return redirect(url_for('adminpage', name='quang'))

if __name__ == '__main__':
    app.run(host='0.0.0.0', debug=False)