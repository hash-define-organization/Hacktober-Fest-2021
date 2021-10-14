# Recycler View Implementation App
<p align = "left">
<img src = "app/src/main/res/drawable/screenShot01.jpg" width = "250">
<img src = "app/src/main/res/drawable/screenShot02.jpg" width = "250">
<img src = "app/src/main/res/drawable/screenShot03.jpg" width = "250">

### Dark Mode

<img src = "app/src/main/res/drawable/screenShot04.jpg" width = "250">
<img src = "app/src/main/res/drawable/screenShot05.jpg" width = "250">
<img src = "app/src/main/res/drawable/screenShot06.jpg" width = "250">
</p>

## Explanation of working of Recycler View

Now taking the example of this app, suppose we want to create an app which shows a list of Data about Dogs.Now there are two solutions that we can choose from:-
* ListView
* Recycler View
We should not use ListView because it has some optimization problems.
<br>
<br>
ListView basically loads all the data into the ram ,  which makes the performance of the app very laggy.
On the other hand Recycler View loads only that much part of data that is needed to fill up the screen at a time.
Which greatly increases the performance.

### Working

Now suppose we want to make an app which shows data about Dogs.

Here first of all we have to collect some resources which we will store in Strings.xml or 