from django.shortcuts import render, HttpResponse

def index(request):
    context = {
            'variable1': "tgis is variale from python",
            'variable2': "tgis is 2nd variale from python"
            }
    return render(request, 'index.html', context)

def about(request):
    return HttpResponse("This is about page")

def contact(request):
    return HttpResponse("This is contact page")

def services(request):
    return HttpResponse("This is srvices pagee")
