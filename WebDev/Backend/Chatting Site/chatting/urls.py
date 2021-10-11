from django.contrib import admin
from django.urls import path
from . import views
from .views import chatting

urlpatterns = [
    path('',views.index,name="index"),
    path('chatting/',views.chatting,name="chatting")
]
