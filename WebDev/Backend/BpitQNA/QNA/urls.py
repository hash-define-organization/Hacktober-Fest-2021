from django.contrib import admin
from django.urls import path,include
from . import views
urlpatterns = [
    path('admin/', admin.site.urls),
    path('',views.home),
    path("AskQuestion/",views.AskQuestion),
    path("<int:id>/",views.specific,name="specificans"),
    path("answer/<int:id>/",views.answer,name="answerhai")
    
]
