from django.db import models
from django.db.models.fields.related import ForeignKey

# Create your models here.


class solvedBy(models.Model):
    First_name=models.CharField(max_length=20)
    Last_name=models.CharField(max_length=20)
    Ans=models.TextField()

    def __str__(self):
        return self.First_name

class question(models.Model):
    Title=models.CharField(max_length=50)
    Message=models.TextField()
    SolvedBy=ForeignKey(solvedBy,on_delete=models.CASCADE,blank=True,null=True)

    def __str__(self):
        return self.Title