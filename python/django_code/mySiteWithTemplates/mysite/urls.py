
from django.contrib import admin
from django.urls import path

from mysite.views import home, about, table

urlpatterns = [
    path('', home, name='home'),
    path('table/', table, name='table'),
    path('about/', about, name='about'),
]
