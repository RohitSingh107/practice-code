from django.shortcuts import render
from datetime import datetime

# Create your views here.


def home(request):

    return render(request, "home.html", context={"today": str(datetime.now().date()), "page" : "Home Page"})


def table(request):
    peoples = [
        {"name": "Rohit", "age": 23},
        {"name": "Name A", "age": 15},
        {"name": "Name B", "age": 12},
        {"name": "Name C", "age": 64},
        {"name": "Name D", "age": 18},
    ]
    return render(request, "table.html", context={"today": str(datetime.now().date()), "peoples" : peoples, "page" : "Table Page"})

def about(request):
    return render(request, "about.html", context={"page" : "About Page"})
