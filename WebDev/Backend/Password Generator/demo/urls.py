
from django.contrib import admin
from django.urls import path
from . import views

urlpatterns = [
    path('admin/', admin.site.urls),
    path('',views.index,name="home"),
    path('analyze',views.analyze,name='analyze'),
    path('create',views.create,name='create')
]
