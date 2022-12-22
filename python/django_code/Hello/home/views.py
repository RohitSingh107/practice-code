from django.shortcuts import render, HttpResponse
from datetime import datetime
from home.models import Contact
from django.core.handlers.wsgi import WSGIRequest
from django.contrib import messages

def index(request: WSGIRequest):
    print(f"type of request is {type(request)}")
    print(request)
    # messages.success(request, "This is test message")
    # context = {
    #         'variable1': "tgis is variale from python",
    #         'variable2': "tgis is 2nd variale from python"
    #         }
    # return render(request, 'index.html', context)
    return render(request, 'index.html')


def about(request: WSGIRequest):
    return render(request, 'about.html')


def contact(request: WSGIRequest):
    print(f"type of request is {type(request)}")
    print(request)
    if request.method == 'POST':
        name =  request.POST.get('name')
        email = request.POST.get('email')
        phone = request.POST.get('phone')
        desc =  request.POST.get('desc')
        contact : Contact = Contact(name = name, email = email, phone = phone, desc = desc, date = datetime.today())
        contact.save()
        messages.success(request, 'Your message has been sent!')
        

    

    return render(request, 'contact.html')


def services(request: WSGIRequest):
    return render(request, 'services.html')
