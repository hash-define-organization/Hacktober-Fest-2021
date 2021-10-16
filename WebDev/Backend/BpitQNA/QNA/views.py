from django.shortcuts import render
from .models import question,solvedBy
# Create your views here.

def home(request):
    
    title = request.POST.get('title', 'No')
    Question=request.POST.get('question', 'No')
    if title!="No" and Question!="No":
        if title and Question:
            print(title)
            value=question(Title=title,Message=Question)
            value.save()
            return render(request,"QNA/thanks.html")
    Questions=question.objects.all()
    return render(request,"QNA/home.html",{
        "Questions":Questions
    })


def AskQuestion(request):

    return render(request,"QNA/AskQuestion.html")


def specific(request,id):

    x=question.objects.get(pk=id)
    if (x.SolvedBy):
        return render(request,"QNA/specific.html",{
            "ans":x
        })
    else:
        return render(request,"QNA/answer.html",{
            "ans":x
        })
    
def answer(request,id):

    x=question.objects.get(pk=id)
    first=request.POST.get('first', 'No')
    last=request.POST.get('last', 'No')
    ans=request.POST.get('ans', 'No')
    if (first!="No" and last!="No" and ans!="No"):
        if first and last and ans :
            value=solvedBy(First_name=first,Last_name=last,Ans=ans)
            value.save()
            x.SolvedBy=value
            x.save()
    return render(request,"QNA/thanks.html")

