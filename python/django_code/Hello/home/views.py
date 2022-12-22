from django.shortcuts import render, HttpResponse


def index(request):
    # context = {
    #         'variable1': "tgis is variale from python",
    #         'variable2': "tgis is 2nd variale from python"
    #         }
    # return render(request, 'index.html', context)
    return render(request, 'index.html')


def about(request):
    return render(request, 'about.html')


def contact(request):
    return render(request, 'contact.html')


def services(request):
    return render(request, 'services.html')
