from flask import Flask, render_template, Response, jsonify
from subprocess import Popen, PIPE

app = Flask(__name__)

p = Popen(['./raspi_microscope'], shell=True, stdout=PIPE, stdin=PIPE)

@app.route('/')
def index():
    return render_template('index.html')

def gen(pro = Popen([''], shell=True, stdout=PIPE, stdin=PIPE)):
    while True:
        frame = pro.stdout.readline().strip()
        yield (b'--frame\r\n'
               b'Content-Type: image/jpeg\r\n\r\n' + frame + b'\r\n\r\n')

@app.route('/video_feed')
def video_feed():
    return Response(gen(p),
                mimetype='multipart/x-mixed-replace; boundary=frame')

if __name__ == '__main__':
    app.run(host='127.0.0.1', debug=True,port="5000")
