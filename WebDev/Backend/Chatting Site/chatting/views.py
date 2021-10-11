from django.shortcuts import render
from django.http import  HttpResponse
from .models import chattingkre 

# Create your views here.

def index(request):
    return render(request,'index.html')

def chatting(request):
    Name = request.POST.get('name', 'No')
    Text=request.POST.get('message', 'No')


    if Name=="No" or Text=="No":
        catprods = chattingkre.objects.all()
        n=len(catprods)
        print(catprods)
        details={'name':Name,'text':Text,'catprods':catprods,'range':range(1,n)}
        return render(request,'chatting.html',details)


    else:
        if Name and Text:
            create=chattingkre(name=Name,text=Text)
            create.save()

        catprods = chattingkre.objects.all()
        n=len(catprods)
        print(catprods)
        details={'name':Name,'text':Text,'catprods':catprods,'range':range(1,n)}
        return render(request,'chatting.html',details)
