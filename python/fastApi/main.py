
from typing import Optional
from fastapi import FastAPI

app = FastAPI()


@app.get('/')
def index():
    return {"data": "blog list"}


@app.get('/blog')
def index(limit: int = 10, published: bool = False, sort: Optional[str] = None):
    if published:
        return {"data": f"{limit} published blogs from db list"}
    else:
        return {"data": f"{limit} blogs from db list"}


@app.get('/blog/unpublished')
def unpublished():
    return {'data': 'all unpublished blogs'}


@app.get('/blog/{id}')
def show(id: int):
    return {"data": id}


@app.get('/blog/{id}/comments')
def comments(id: int, limit=10):
    return {'data': {'1', '2', '3'}}
