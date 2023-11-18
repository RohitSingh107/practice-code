
from django.contrib import admin
from django.urls import path

from mysite.views import home, about, table, formm_page

urlpatterns = [
    path('', home, name='home'),
    path('table/', table, name='table'),
    path('about/', about, name='about'),
    path('form/', formm_page, name='form'),
]
