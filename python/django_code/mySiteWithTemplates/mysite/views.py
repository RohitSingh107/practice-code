from django.http import HttpResponseRedirect
from django.shortcuts import render
from datetime import datetime

from mysite.forms import MyForm



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

def formm_page(request):
    print("======================================h1")

    if request.method == "POST":
        print("======================================h2")
        myForm = MyForm(request.POST)
        print("======================================h3")
        if myForm.is_valid():
            print("======================================h4")

            print("form data is ", myForm.cleaned_data) # Can do anything here with data
            return HttpResponseRedirect("/")
        else:
            print("======================================h6")

            return HttpResponseRedirect("/form/")

    else:
        print("======================================h5")
        myForm = MyForm()
        return render(request, "form.html", context={"page" : "Form Page", "myForm" : myForm})
