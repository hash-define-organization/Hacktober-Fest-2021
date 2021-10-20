from flask import Flask, render_template, redirect
from flask_restful import Api, Resource, reqparse,request
import pandas as pd
import random
import string

app = Flask(__name__)
api = Api(app)

class Urls(Resource):
    def get(self):
        data = pd.read_csv('urls.csv',delimiter=',')
        data = data.to_dict('records')
        print(data)
        return {'data' : data}, 200

    def post(self):
        parser = reqparse.RequestParser()
        parser.add_argument('url', required=True)
        args = parser.parse_args()

        data = pd.read_csv('urls.csv',delimiter=',')

        if( data['url'].str.contains(str(args['url'])).any()):

            idx = list(data['url'].values).index(args['url'])

            nanoid = data['nanoid'].values[idx]
            url="http://localhost:5000/?page="+nanoid
            return url

        id = ''.join(random.choices(string.ascii_uppercase + string.digits, k = 8))

        new_data = pd.DataFrame({
            'url'          : [args['url']],
            'nanoid'       : [id],
        })

        data = data.append(new_data, ignore_index = True)
        data.to_csv('urls.csv', index=False)
        url="http://localhost:5000/?page="+id
        return url

# Add URL endpoints
api.add_resource(Urls, '/api')

@app.route("/")
def index():

    nanoid = request.args.get('page', default = "/" , type = str)

    if nanoid == "/":
        return render_template('index.html')

    data = pd.read_csv('urls.csv',delimiter=',')

    if nanoid in set(data["nanoid"]):
        url = data["url"][ list(data['nanoid'].values).index(nanoid) ]

        if url.find("http://") != 0 and url.find("https://") != 0:
            url = "http://" + url

        return redirect(url)

    else:
        return "Bad Request",404

if __name__ == '__main__':
    app.run()
