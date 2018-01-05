#__author__ = 'jenil'
import webbrowser
import time
total_breaks=3
break_count=0
print("the time is now"+time.ctime())
while(break_count<total_breaks):
    time.sleep(10)
    webbrowser.open_new_tab("http://www.youtube.com")
    break_count=break_count+1
