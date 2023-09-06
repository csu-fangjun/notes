#!/usr/bin/env python3

# flask --app hello run

from flask import Flask
from markupsafe import escape

print("__name__", __name__)

app = Flask(__name__)


@app.route("/")
def hello_world():
    app.logger.debug("A value for debugging")
    app.logger.warning("A warning occurred (%d apples)", 42)
    app.logger.error("An error occurred")

    return "<p>Hello world!</p>"


@app.route("/<name>")
def hello(name):
    return f"Hello, {escape(name)}!"


@app.route("/user/<username>")
def show_user_profile(username):
    # show the user profile for that user
    return f"User {escape(username)}"


# If a user uses /post/ab, it will show Not Found
@app.route("/post/<int:post_id>")
def show_post(post_id):
    print("type(post_id)", type(post_id))  # type(pos_id) <class 'int'>
    # show the post with the given id, the id is an integer
    return f"Post {post_id}"


@app.route("/path/<path:subpath>")
def show_subpath(subpath):
    print("type(subpath)", type(subpath))  # type(subpath) <class 'str'>
    # show the subpath after /path/
    return f"Subpath {escape(subpath)}"
