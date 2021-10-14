from django.contrib import admin
from .models import question,solvedBy
# Register your models here.

admin.site.register(question)

admin.site.register(solvedBy)