###   ANTI ARP POISONING TOOL
''' 
This is a tool designed to detect, prevent and recover from an ARP poisoning attack.
'''

import os
import time

# This function scans the arp cache and stores the mac addresses and ip addresses in separate lists. Then it checks if the subsequent mac addresses is already present in the list. If the mac address is already there in the list, then we can say that the system's ARP cache is poisoned. else it is safe.

def scan():
         mac_list=[]
	ip_list= []
	with os.popen('arp -a') as f:
		data = f.read()
	data=data.split()

	flag = 0 # 0 means safe
	for i in range(len(data)):
		if(data[i]=="at" and data[i+1]!="<incomplete>" ):
			#print(data[i-1]+":"+data[i+1])
			if data[i+1] in mac_list:
				flag = 1
				print("ARP CACHE IS POISONED!!")
				print("The attacker's mac address is:" +data[i+1])
				return 1
			else:
				mac_list.append(data[i+1])
				ip_list.append(data[i-1])
	if(flag == 0):
		print("ARP CACHE IS CLEAN\n\n\n")
		return 0



#This function is used to get the ARP cache of the system and display it

def view_cache():
	with os.popen('arp') as f:
		data = f.read()
	print(data)



#This function is used to create a static entry in the arp cache. The user is required to enter the ip address whose entry they would like to change along with the correct mac address for that ip

def create_static_arp_entry():
	ip = raw_input("Enter the ip address to add:")
	mac = raw_input("Enter the mac address to add:")
	pa = raw_input("Enter password:")
	string = "sudo arp -s "+ip+" "+mac
	os.popen("sudo -S %s"%(string), 'w').write(pa)



#This function converts the entire ARP cache entries into static entries. This works by reading the ip and mac addresses stored in the cache and then adding static arp entries using these values. Static ARP entry is made using the command "sudo arp -s <ip> <mac>"
def make_static_arp_cache():
	mac_list=[]
	ip_list=[]
	with os.popen('arp -a') as f:
		data = f.read()
	data=data.split()
	for i in range(len(data)):
		if(data[i]=="at" and data[i+1]!="<incomplete>" ):
			ip_list.append(data[i-1][1:len(data[i-1])-1])
			mac_list.append(data[i+1])
	pa = raw_input("Enter password:")
	#print(pa)
	for i in range(len(ip_list)):
		#print("Entry:"+ip_list[i]+":"+mac_list[i])
		string = "sudo arp -s "+ip_list[i]+" "+mac_list[i]
		os.popen("sudo -S %s"%(string), 'w').write(pa)
		#print("ADDED")


#This function serves the purpose to clear the ARP cache of the system using "sudo arp -d <ip>"	
def clear_arp_cache():
	mac_list=[]
	ip_list=[]
	with os.popen('arp -a') as f:
		data = f.read()
	data=data.split()
	for i in range(len(data)):
		if(data[i]=="at" and data[i+1]!="<incomplete>" ):
			ip_list.append(data[i-1][1:len(data[i-1])-1])
			mac_list.append(data[i+1])
	pa = raw_input("Enter password:")
	print(pa)
	for i in range(len(ip_list)):
		#print("Entry:"+ip_list[i]+":"+mac_list[i])
		string = "sudo arp -d "+ip_list[i]
		os.popen("sudo -S %s"%(string), 'w').write(pa)
		#print("REMOVED")


#This function continuously checks if the arp cache is poisoned 
def repeat():
	while(1):
		mac_list=[]
		ip_list=[]
		with os.popen('arp -a') as f:
			data = f.read()
		data=data.split()

		flag = 0 
		for i in range(len(data)):
			if(data[i]=="at" and data[i+1]!="<incomplete>" ):
				#print(data[i-1]+":"+data[i+1])
				if data[i+1] in mac_list:
					flag = 1
					print("ARP CACHE IS POISONED!!")
					print("The attacker's mac address is:" +data[i+1])
					return 1

				else:
					mac_list.append(data[i+1])
					ip_list.append(data[i-1])
				
		if(flag == 0):
			print("ARP CACHE IS CLEAN")
		del mac_list[:]
		del ip_list[:]
		time.sleep(3)

clean_ip = []
clean_mac = []

#This function is called at the beginning of the program to get a clean arp cache
def clean_arp():
	with os.popen('arp -a') as f:
		data = f.read()
	# check if the arp is already poisoned
	x = scan()
	if x==0:
		data=data.split()
		for i in range(len(data)):
			if(data[i]=="at" and data[i+1]!="<incomplete>" ):
				clean_ip.append(data[i-1][1:len(data[i-1])-1])
				clean_mac.append(data[i+1])
		return 1
	else:
		return 0


clean_status = clean_arp()
print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
	
#menu
while(1):
	print("ANTI-ARP POISONING TOOL")
	print("-------- --------- ----")
	print("\n1.Scan for possible ARP attacks\n2.View your ARP cache\n3.Create a static ARP entry\n4.Make all entries of ARP as static\n5.Clear ARP cache\n6.Run continuous test\n7.Exit\n\nEnter your option:")
	choice=int(input())
	if(choice==7):
		break
	else:
		if(choice==1):
			scan()
		elif(choice==2):
			view_cache()
		elif(choice==3):
			create_static_arp_entry()
		elif(choice==4):
			make_static_arp_cache()
		elif(choice==5):
			clear_arp_cache()
		elif(choice==6):
			x = repeat()
			if x==1:
				print("\n\nYou are under attack, please take necessary actions\n")
				print("Press 1 if you remember the actual mac address")
				print("Press 2 if you don't remember the actual mac address")
				
				c=int(input())
				if(c==1):
					view_cache()
					while(1):
						create_static_arp_entry()
						print("\nDo you want to change more mac addresses?(y/n)")
						next = input()
						if(next != 'y'):
							break
				if(c==2):
					if(clean_status==1):
						pa = raw_input("Enter password:")
						print(pa)
						for i in range(len(clean_ip)):
							#print("Entry:"+ip_list[i]+":"+mac_list[i])
							string = "sudo arp -s "+clean_ip[i]+" "+clean_mac[i]
							os.popen("sudo -S %s"%(string), 'w').write(pa)
							#print("ADDED")
					else:
						print("\nNo clean arp available!! Cleaning cache")
						clear_arp_cache()
						
						
					
						
									
									
