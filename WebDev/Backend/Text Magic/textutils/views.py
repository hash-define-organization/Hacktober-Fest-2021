from django.http import HttpResponse
from django.shortcuts import render


def index(request):
    return render(request, 'index.html')

def faltu(request):
    return HttpResponse("faltu")

def analyze(request):
    #Get the text
    djtext = request.POST.get('text', 'default')
    #copy of text 
    copyOfText=djtext
    # Check checkbox values
    removepunc = request.POST.get('removepunc', 'off')
    fullcaps = request.POST.get('fullcaps', 'off')
    newlineremover = request.POST.get('newlineremover', 'off')
    extraspaceremover = request.POST.get('extraspaceremover', 'off')
    numberremover = request.POST.get('numberremover','off')
    fulltextanalyze =request.POST.get('fulltextanalyze','off')

    #Check which checkbox is on
    if removepunc == "on":
        punctuations = '''!()-[]{};:'"\,<>./?@#$%^&*_~'''
        analyzed = ""
        for char in djtext:
            if char not in punctuations:
                analyzed = analyzed + char

        params = {'purpose':'Removed Punctuations', 'analyzed_text': analyzed,'original_text':copyOfText}
        djtext = analyzed

    if(fullcaps=="on"):
        analyzed = ""
        for char in djtext:
            analyzed = analyzed + char.upper()

        params = {'purpose': 'Changed to Uppercase', 'analyzed_text': analyzed,'original_text':copyOfText}
        djtext = analyzed

    if(extraspaceremover=="on"):
        analyzed = ""
        for index, char in enumerate(djtext):
            # It is for if a extraspace is in the last of the string
            if char == djtext[-1]:
                    if not(djtext[index] == " "):
                        analyzed = analyzed + char

            elif not(djtext[index] == " " and djtext[index+1]==" "):                        
                analyzed = analyzed + char

        params = {'purpose': 'Removed NewLines', 'analyzed_text': analyzed,'original_text':copyOfText}
        djtext = analyzed

    if (newlineremover == "on"):
        analyzed = ""
        for char in djtext:
            if char != "\n" and char!="\r":
                analyzed = analyzed + char

        params = {'purpose': 'Removed NewLines', 'analyzed_text': analyzed,'original_text':copyOfText}
    
    if (numberremover == "on"):
        analyzed = ""
        numbers = '0123456789'

        for char in djtext:
            if char not in numbers:
                analyzed = analyzed + char
        
        params = {'purpose': 'Removed Number', 'analyzed_text': analyzed,'original_text':copyOfText}
        djtext = analyzed
        
    if fulltextanalyze == "on":
        upper=0
        lower=0
        digit=0
        for char in djtext:
            if char.islower():
                lower+=1
            elif char.isupper():
                upper+=1
            elif char.isdigit():
                digit+=1
        params = {'purpose':'Analyze Full Text(Number of Uppercase,Lowercase,Digits)','lower':lower,'upper':upper,'digit':digit}
        print(upper,lower,digit)
        return render(request, 'analyze2.html', params)

    if(removepunc != "on" and newlineremover!="on" and extraspaceremover!="on" and fullcaps!="on" and numberremover != "on"):
        return render(request, 'analyze3.html')


    return render(request, 'analyze.html', params)

def about(request):
    return render(request, 'about.html')