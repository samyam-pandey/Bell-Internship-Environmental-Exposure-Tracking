import csv
import glob
from shapely.geometry import Point # Point class
import shapely.geometry
#from functools import partial
import fiona
#from shapely.ops import transform
#import pyproj
#from pyproj import Proj, CRS,transform
from collections import defaultdict

#takes an input file(uses the address of the csv file)
#import time

from dateutil.parser import parse
import calendar

path = r&quot;C:\Users\SPANDE01\Desktop\code_t\position_history\*.csv&quot;
path=glob.glob(path)
fileinput = str(input(&quot;Which file do you want?&quot;))
#Declare a global dictionay

dd=defaultdict(list)

with open(fileinput, &#39;r&#39;) as file:
reader = csv.DictReader(file, delimiter=&#39;,&#39;)
for row in reader:
y1=float(row[&quot;ACTV_PIL_PVT_LATITUDE (DEG)&quot;])
x1=float(row[&quot;ACTV_PIL_PVT_LONGITUDE (DEG)&quot;])

coordinates = Point(x1, y1)
# gets all the features of the given lat and long
with fiona.open(r&quot;C:\Projects\Corosion_Erosion_Analysis\Data\Observered\1976-
2000_GIS_Renamed\1976-2000_renamed.shp&quot;) as open_function:
for idx,feature in enumerate(open_function):
G= shapely.geometry.asShape(feature[&#39;geometry&#39;])
if G.intersects(coordinates):

output_climate=dict(feature[&#39;properties&#39;])
output_climate[&quot;DateTime&quot;]=(row[&quot;DateTime&quot;])
output_climate[&quot;ACTV_PIL_PVT_LATITUDE (DEG)&quot;]=(row[&quot;ACTV_PIL_PVT_LATITUDE (DEG)&quot;])
output_climate[&quot;ACTV_PIL_PVT_LONGITUDE (DEG)&quot;]=(row[&quot;ACTV_PIL_PVT_LONGITUDE
(DEG)&quot;])

for key, value in output_climate.items():
dd[key].append(value)

i_d=dd[&#39;Koppen Id&#39;]

#fieldnames=[&quot;ID&quot;,&quot;GRIDCODE&quot;,&quot;Koppen Id&quot;,&quot;Main Clima&quot;,&quot;Precipitat&quot;,&quot;Temperatur&quot;,&quot;DateTime&quot;
# ,&quot;ACTV_PIL_PVT_LATITUDE (DEG)&quot;,&quot;ACTV_PIL_PVT_LONGITUDE (DEG)&quot;]
# wites all the corresponiding data for the given long and lat to a out put csv file
headers=dd.keys()
with (open(&quot;C:/Users/SPANDE01/Desktop/code_t/output/test_out.csv&quot;,&quot;w&quot; )) as a_file:
writer=csv.writer(a_file )
writer.writerows([headers])
writer.writerows(zip(*dd.values()))
#df=pd.DataFrame(a_file, columns = [&quot;ID&quot;,&quot;GRIDCODE&quot;,&quot;Koppen Id&quot;,&quot;Main
Clima&quot;,&quot;Precipitat&quot;,&quot;Temperatur&quot;,&quot;DateTime&quot;,&quot;ACTV_PIL_PVT_LATITUDE
(DEG)&quot;,&quot;ACTV_PIL_PVT_LONGITUDE (DEG)&quot;])
#for key, value in dd.items():
#writer.writerow([key]+value)

#pd.pivot_table(dd, index=[&quot;ID&quot;,&quot;GRIDCODE&quot;,&quot;Koppen Id&quot;,&quot;Main
Clima&quot;,&quot;Precipitat&quot;,&quot;Temperatur&quot;,&quot;DateTime&quot;,&quot;ACTV_PIL_PVT_LATITUDE
(DEG)&quot;,&quot;ACTV_PIL_PVT_LONGITUDE (DEG)&quot;])
a_file.close()

date_out=dd[&#39;DateTime&#39;]

print(&quot;\n&quot;)
print(&quot;Done writing to csv&quot;)
print(&quot;\n&quot;)
# get Dtae/time and put it into a list/array
# then sort it the list
#date_out=sorted(date_out)

# this takes out the symbols in the data
#new_date=[]
#for k in date_out:
#line=re.sub(&#39;[:.!@#$]&#39;, &#39;&#39;, k)
#new_date.append(line)

#new_date = [int(i) for i in new_date]
#print(new_date)
# then from the min check if its its in one climate then find the difference
#merged_list = list(tuple(zip(i_d, date_out)))
#result={}
dicts = {key: [] for key in dd[&#39;Koppen Id&#39;]}
for k, v in zip(i_d, date_out):
dicts[k].append(v)
#print (dicts)

#this changes the values to unix time in key value cfa
unix_af=[]
unix_am=[]
unix_as=[]
unix_aw=[]
unix_bwk=[]

unix_bwh=[]
unix_bsk=[]
unix_bsh=[]
unix_cfa=[]
unix_cfb=[]
unix_cfc=[]
unix_csa=[]
unix_csb=[]
unix_csc=[]
unix_cwa=[]
unix_cwb=[]
unix_cwc=[]
unix_dfa=[]
unix_dfb=[]
unix_dfc=[]
unix_dfd=[]
unix_dsa=[]
unix_dsc=[]
unix_dsd=[]
unix_dwa=[]
unix_dwb=[]
unix_dwc=[]
unix_dwd=[]
unix_ef=[]
unix_et=[]
if dicts.get(&#39;Af&#39;):
for i in dicts.get(&#39;Af&#39;):
time_obj = parse(i)
unixtime = calendar.timegm(time_obj.timetuple())

unix_af.append(unixtime)
if dicts.get(&#39;Am&#39;):
for i in dicts.get(&#39;Am&#39;):
time_obj = parse(i)
unixtime = calendar.timegm(time_obj.timetuple())
unix_am.append(unixtime)
if dicts.get(&#39;As&#39;):
for i in dicts.get(&#39;As&#39;):
time_obj = parse(i)
unixtime = calendar.timegm(time_obj.timetuple())
unix_as.append(unixtime)
if dicts.get(&#39;Aw&#39;):
for i in dicts.get(&#39;Aw&#39;):
time_obj = parse(i)
unixtime = calendar.timegm(time_obj.timetuple())
unix_aw.append(unixtime)
if dicts.get(&#39;BWk&#39;):
for i in dicts.get(&#39;BWk&#39;):
time_obj = parse(i)
unixtime = calendar.timegm(time_obj.timetuple())
unix_bwk.append(unixtime)
if dicts.get(&#39;BWh&#39;):
for i in dicts.get(&#39;BWh&#39;):
time_obj = parse(i)
unixtime = calendar.timegm(time_obj.timetuple())
unix_bwh.append(unixtime)
if dicts.get(&#39;BSk&#39;):
for i in dicts.get(&#39;BSk&#39;):
time_obj = parse(i)

unixtime = calendar.timegm(time_obj.timetuple())
unix_bsk.append(unixtime)
if dicts.get(&#39;BSh&#39;):
for i in dicts.get(&#39;BSh&#39;):
time_obj = parse(i)
unixtime = calendar.timegm(time_obj.timetuple())
unix_bsh.append(unixtime)
if dicts.get(&#39;Cfa&#39;):
for i in dicts.get(&#39;Cfa&#39;):
time_obj = parse(i)
unixtime = calendar.timegm(time_obj.timetuple())
unix_cfa.append(unixtime)
if dicts.get(&#39;Cfb&#39;):
for i in dicts.get(&#39;Cfb&#39;):
time_obj = parse(i)
unixtime = calendar.timegm(time_obj.timetuple())
unix_cfb.append(unixtime)
if dicts.get(&#39;Cfc&#39;):
for i in dicts.get(&#39;Cfc&#39;):
time_obj = parse(i)
unixtime = calendar.timegm(time_obj.timetuple())
unix_cfc.append(unixtime)
if dicts.get(&#39;Csa&#39;):
for i in dicts.get(&#39;Csa&#39;):
time_obj = parse(i)
unixtime = calendar.timegm(time_obj.timetuple())
unix_csa.append(unixtime)
if dicts.get(&#39;Csb&#39;):
for i in dicts.get(&#39;Csb&#39;):

time_obj = parse(i)
unixtime = calendar.timegm(time_obj.timetuple())
unix_csb.append(unixtime)
if dicts.get(&#39;Csc&#39;):
for i in dicts.get(&#39;Csc&#39;):
time_obj = parse(i)
unixtime = calendar.timegm(time_obj.timetuple())
unix_csc.append(unixtime)
if dicts.get(&#39;Cwa&#39;):
for i in dicts.get(&#39;Cwa&#39;):
time_obj = parse(i)
unixtime = calendar.timegm(time_obj.timetuple())
unix_cwa.append(unixtime)
if dicts.get(&#39;Cwb&#39;):
for i in dicts.get(&#39;Cwb&#39;):
time_obj = parse(i)
unixtime = calendar.timegm(time_obj.timetuple())
unix_cwb.append(unixtime)
if dicts.get(&#39;Cwc&#39;):
for i in dicts.get(&#39;Cwc&#39;):
time_obj = parse(i)
unixtime = calendar.timegm(time_obj.timetuple())
unix_cwc.append(unixtime)
if dicts.get(&#39;Dfa&#39;):
for i in dicts.get(&#39;Dfa&#39;):
time_obj = parse(i)
unixtime = calendar.timegm(time_obj.timetuple())
unix_dfa.append(unixtime)
if dicts.get(&#39;Dfb&#39;):

for i in dicts.get(&#39;Dfb&#39;):
time_obj = parse(i)
unixtime = calendar.timegm(time_obj.timetuple())
unix_dfb.append(unixtime)
if dicts.get(&#39;Dfc&#39;):
for i in dicts.get(&#39;Dfc&#39;):
time_obj = parse(i)
unixtime = calendar.timegm(time_obj.timetuple())
unix_dfc.append(unixtime)
if dicts.get(&#39;Dfd&#39;):
for i in dicts.get(&#39;Dfd&#39;):
time_obj = parse(i)
unixtime = calendar.timegm(time_obj.timetuple())
unix_dfd.append(unixtime)
if dicts.get(&#39;Dsa&#39;):
for i in dicts.get(&#39;Dsa&#39;):
time_obj = parse(i)
unixtime = calendar.timegm(time_obj.timetuple())
unix_dsa.append(unixtime)
if dicts.get(&#39;Dsc&#39;):
for i in dicts.get(&#39;Dsc&#39;):
time_obj = parse(i)
unixtime = calendar.timegm(time_obj.timetuple())
unix_dsc.append(unixtime)
if dicts.get(&#39;Dsd&#39;):
for i in dicts.get(&#39;Dsd&#39;):
time_obj = parse(i)
unixtime = calendar.timegm(time_obj.timetuple())
unix_dsd.append(unixtime)

if dicts.get(&#39;Dwa&#39;):
for i in dicts.get(&#39;Dwa&#39;):
time_obj = parse(i)
unixtime = calendar.timegm(time_obj.timetuple())
unix_dwa.append(unixtime)
if dicts.get(&#39;Dwb&#39;):
for i in dicts.get(&#39;Dwb&#39;):
time_obj = parse(i)
unixtime = calendar.timegm(time_obj.timetuple())
unix_dwb.append(unixtime)
if dicts.get(&#39;Dwc&#39;):
for i in dicts.get(&#39;Dwc&#39;):
time_obj = parse(i)
unixtime = calendar.timegm(time_obj.timetuple())
unix_dwc.append(unixtime)
if dicts.get(&#39;Dwd&#39;):
for i in dicts.get(&#39;Dwd&#39;):
time_obj = parse(i)
unixtime = calendar.timegm(time_obj.timetuple())
unix_dwd.append(unixtime)
if dicts.get(&#39;EF&#39;):
for i in dicts.get(&#39;EF&#39;):
time_obj = parse(i)
unixtime = calendar.timegm(time_obj.timetuple())
unix_ef.append(unixtime)
if dicts.get(&#39;ET&#39;):
for i in dicts.get(&#39;ET&#39;):
time_obj = parse(i)
unixtime = calendar.timegm(time_obj.timetuple())

unix_et.append(unixtime)

## do this for all the koppen labels make the thin and the if statements
#max_cfa=max(dicts.get(&#39;Cfa&#39;))#max value
#min_cfa=min(dicts.get(&#39;Cfa&#39;))#min value
if dicts.get(&#39;Af&#39;):
max_af=max(unix_af)
min_af=min(unix_af)
if dicts.get(&#39;Am&#39;):
max_am=max(unix_am)
min_am=min(unix_am)
if dicts.get(&#39;As&#39;):
max_as=max(unix_as)
min_as=min(unix_as)
if dicts.get(&#39;Aw&#39;):
max_aw=max(unix_aw)
min_aw=min(unix_aw)
if dicts.get(&#39;BWk&#39;):
max_bwk=max(unix_bwk)
min_bwk=min(unix_bwk)
if dicts.get(&#39;BwH&#39;):
max_bwh=max(unix_bwh)
min_bwh=min(unix_bwh)
if dicts.get(&#39;BSk&#39;):

max_bsk=max(unix_bsk)
min_bsk=min(unix_bsk)
if dicts.get(&#39;BSh&#39;):
max_bsh=max(unix_bsh)
min_bsh=min(unix_bsh)
if dicts.get(&#39;Cfa&#39;):
max_cfa=max(unix_cfa)
min_cfa=min(unix_cfa)
if dicts.get(&#39;Cfb&#39;):
max_cfb=max(unix_cfb)
min_cfb=min(unix_cfb)
if dicts.get(&#39;Cfc&#39;):
max_cfc=max(unix_cfc)
min_cfc=min(unix_cfc)
if dicts.get(&#39;Csa&#39;):
max_csa=max(unix_csa)
min_csa=min(unix_csa)
if dicts.get(&#39;Csb&#39;):
max_csb=max(unix_csb)
min_csb=min(unix_csb)
if dicts.get(&#39;Csc&#39;):
max_csc=max(unix_csc)
min_csc=min(unix_csc)
if dicts.get(&#39;Cwa&#39;):
max_cwa=max(unix_cwa)
min_cwa=min(unix_cwa)
if dicts.get(&#39;Cwb&#39;):
max_cwb=max(unix_cwb)
min_cwb=min(unix_cwb)

if dicts.get(&#39;Cwc&#39;):
max_cwc=max(unix_cwc)
min_cwc=min(unix_cwc)
if dicts.get(&#39;Dfa&#39;):
max_dfa=max(unix_dfa)
min_dfa=min(unix_dfa)
if dicts.get(&#39;Dfb&#39;):
max_dfb=max(unix_dfb)
min_dfb=min(unix_dfb)
if dicts.get(&#39;Dfc&#39;):
max_dfc=max(unix_dfc)
min_dfc=min(unix_dfc)
if dicts.get(&#39;Dfd&#39;):
max_dfd=max(unix_dfd)
min_dfd=min(unix_dfd)
if dicts.get(&#39;Dsa&#39;):
max_dsa=max(unix_dsa)
min_dsa=min(unix_dsa)
if dicts.get(&#39;Dsc&#39;):
max_dsc=max(unix_dsc)
min_dsc=min(unix_dsc)
if dicts.get(&#39;Dsd&#39;):
max_dsd=max(unix_dsd)
min_dsd=min(unix_dsd)
if dicts.get(&#39;Dwa&#39;):
max_dwa=max(unix_dwa)
min_dwa=min(unix_dwa)
if dicts.get(&#39;Dwb&#39;):
max_dwb=max(unix_dwb)

min_dwb=min(unix_dwb)
if dicts.get(&#39;Dwc&#39;):
max_dwc=max(unix_dwc)
min_dwc=min(unix_dwc)
if dicts.get(&#39;Dwd&#39;):
max_dwd=max(unix_dwd)
min_dwd=min(unix_dwd)
if dicts.get(&#39;EF&#39;):
max_ef=max(unix_ef)
min_ef=min(unix_ef)
if dicts.get(&#39;ET&#39;):
max_et=max(unix_et)
min_et=min(unix_et)

## do this for all the koppen labels make the thin and the if statements
#cfa=&#39;Cfa&#39;
#if &#39;Cfa&#39; in dicts.keys():
if dicts.get(&#39;Af&#39;):
total_af=max_af-min_af
#str(total_af)
print(&quot;the total duration is for climate Af is: &quot;, total_af, &quot;seconds&quot;)
else:
total_af=0
print(&quot; The total duration is 0 for climate Af.&quot;)

if dicts.get(&#39;Am&#39;):
total_am=max_am-min_am
#str(total_am)

print(&quot;the total duration is for climate Am is: &quot;, total_am, &quot;seconds&quot;)
else:
total_am=0
print(&quot; The total duration is 0 for climate Am.&quot;)

if dicts.get(&#39;As&#39;):
total_as=max_as-min_as
#str(total_as)
print(&quot;the total duration is for climate As is: &quot;, total_as, &quot;seconds&quot;)
else:
total_as=0
print(&quot; The total duration is 0 for climate As.&quot;)

if dicts.get(&#39;Aw&#39;):
total_aw=max_aw-min_aw
#str(total_aw)
print(&quot;the total duration is for climate Aw is: &quot;, total_aw, &quot;seconds&quot;)
else:
total_aw=0
print(&quot; The total duration is 0 for climate Aw.&quot;)
if dicts.get(&#39;BWk&#39;):
total_bwk=max_bwk-min_bwk
#str(total_bwk)
print(&quot;the total duration is for climate BWk is: &quot;, total_bwk, &quot;seconds&quot;)
else:
total_bwk=0
print(&quot; The total duration is 0 for climate BWk.&quot;)
if dicts.get(&#39;BWh&#39;):
total_bwh=max_bwh-min_bwh

#str(total_bwh)
print(&quot;the total duration is for climate BWh is: &quot;, total_bwh, &quot;seconds&quot;)
else:
total_bwh=0
print(&quot; The total duration is 0 for climate BWh.&quot;)
if dicts.get(&#39;BSk&#39;):
total_bsk=max_bsk-min_bsk
#str(total_bsk)
print(&quot;the total duration is for climate BSk is: &quot;, total_bsk, &quot;seconds&quot;)
else:
total_bsk=0
print(&quot; The total duration is 0 for climate BSk.&quot;)
if dicts.get(&#39;BSh&#39;):
total_bsh=max_bsh-min_bsh
#str(total_bsh)
print(&quot;the total duration is for climate BSh is: &quot;, total_bsh, &quot;seconds&quot;)
else:
total_bsh=0
print(&quot; The total duration is 0 for climate Af.&quot;)
if dicts.get(&#39;Cfa&#39;):
total_cfa=max_cfa-min_cfa
#str(total_cfa)
print(&quot;the total duration is for climate Cfa is: &quot;, total_cfa, &quot;seconds&quot;)
else:
total_cfa=0
print(&quot; The total duration is 0 for climate Cfa.&quot;)
if dicts.get(&#39;Cfb&#39;):
total_cfb=max_cfb-min_cfb
#str(total_cfb)

print(&quot;the total duration is for climate Cfb is: &quot;, total_cfb, &quot;seconds&quot;)
else:
total_cfb=0
print(&quot; The total duration is 0 for climate Cfb.&quot;)
if dicts.get(&#39;Cfc&#39;):
total_cfc=max_cfc-min_cfc
#str(total_cfc)
print(&quot;the total duration is for climate cfc is: &quot;, total_cfc, &quot;seconds&quot;)
else:
total_cfc=0
print(&quot; The total duration is 0 for climate Af.&quot;)
if dicts.get(&#39;Csa&#39;):
total_csa=max_csa-min_csa
#str(total_csa)
print(&quot;the total duration is for climate csa is: &quot;, total_csa, &quot;seconds&quot;)
else:
total_csa=0
print(&quot; The total duration is 0 for climate Af.&quot;)
if dicts.get(&#39;Csb&#39;):
total_csb=max_csb-min_csb
#str(total_csb)
print(&quot;the total duration is for climate csb is: &quot;, total_csb, &quot;seconds&quot;)
else:
total_csb=0
print(&quot; The total duration is 0 for climate Af.&quot;)
if dicts.get(&#39;Csc&#39;):
total_csc=max_csc-min_csc
#str(total_csc)
print(&quot;the total duration is for climate csc is: &quot;, total_csc, &quot;seconds&quot;)

else:
total_csc=0
print(&quot; The total duration is 0 for climate Af.&quot;)
if dicts.get(&#39;Cwa&#39;):
total_cwa=max_cwa-min_cwa
#str(total_cwa)
print(&quot;the total duration is for climate Cwa is: &quot;, total_cwa, &quot;seconds&quot;)
else:
total_cwa=0
print(&quot; The total duration is 0 for climate Cwa.&quot;)
if dicts.get(&#39;Cwb&#39;):
total_cwb=max_cwb-min_cwb
#str(total_cwb)
print(&quot;the total duration is for climate Cwb is: &quot;, total_cwb, &quot;seconds&quot;)
else:
total_cwb=0
print(&quot; The total duration is 0 for climate Cwb.&quot;)
if dicts.get(&#39;Cwc&#39;):
total_cwc=max_cwc-min_cwc
#str(total_cwc)
print(&quot;the total duration is for climate Cwc is: &quot;, total_cwc, &quot;seconds&quot;)
else:
total_cwc=0
print(&quot; The total duration is 0 for climate Cwc.&quot;)
if dicts.get(&#39;Dfa&#39;):
total_dfa=max_dfa-min_dfa
#str(total_dfa)
print(&quot;the total duration is for climate Dfa is: &quot;, total_dfa, &quot;seconds&quot;)
else:

total_dfa=0
print(&quot; The total duration is 0 for climate Dfa.&quot;)
if dicts.get(&#39;Dfb&#39;):
total_dfb=max_dfb-min_dfb
#str(total_dfb)
print(&quot;the total duration is for climate Dfb is: &quot;, total_dfb, &quot;seconds&quot;)
else:
total_dfb=0
print(&quot; The total duration is 0 for climate Dfb.&quot;)
if dicts.get(&#39;Dfc&#39;):
total_dfc=max_dfc-min_dfc
# str(total_dfc)
print(&quot;the total duration is for climate Dfc is: &quot;, total_dfc, &quot;seconds&quot;)
else:
total_dfc=0
print(&quot; The total duration is 0 for climate Dfc.&quot;)
if dicts.get(&#39;Dfd&#39;):
total_dfd=max_dfd-min_dfd
#str(total_dfd)
print(&quot;the total duration is for climate Dfd is: &quot;, total_dfd, &quot;seconds&quot;)
else:
total_dfd=0
print(&quot; The total duration is 0 for climate Dfd.&quot;)
if dicts.get(&#39;Dsa&#39;):
total_dsa=max_dsa-min_dsa
# str(total_dsa)
print(&quot;the total duration is for climate Dsa is: &quot;, total_dsa, &quot;seconds&quot;)
else:
total_dsa=0

print(&quot; The total duration is 0 for climate Dsa.&quot;)
if dicts.get(&#39;Dsc&#39;):
total_dsc=max_dsc-min_dsc
# str(total_dsc)
print(&quot;the total duration is for climate Dsc is: &quot;, total_dsc, &quot;seconds&quot;)
else:
total_dsc=0
print(&quot; The total duration is 0 for climate Dsc.&quot;)
if dicts.get(&#39;Dsd&#39;):
total_dsd=max_dsd-min_dsd
#str(total_dsd)
print(&quot;the total duration is for climate Dsd is: &quot;, total_dsd, &quot;seconds&quot;)
else:
total_dsd=0
print(&quot; The total duration is 0 for climate Dsd.&quot;)
if dicts.get(&#39;Dwa&#39;):
total_dwa=max_dwa-min_dwa
#str(total_dwa)
print(&quot;the total duration is for climate Dwa is: &quot;, total_dwa, &quot;seconds&quot;)
else:
total_dwa=0
print(&quot; The total duration is 0 for climate Dwa.&quot;)
if dicts.get(&#39;Dwb&#39;):
total_dwb=max_dwb-min_dwb
#str(total_dwb)
print(&quot;the total duration is for climate Dwb is: &quot;, total_dwb, &quot;seconds&quot;)
else:
total_dwb=0
print(&quot; The total duration is 0 for climate Dwb.&quot;)

if dicts.get(&#39;Dwc&#39;):
total_dwc=max_dwc-min_dwc
#str(total_dwc)
print(&quot;the total duration is for climate Dwc is: &quot;, total_dwc, &quot;seconds&quot;)
else:
total_dwc=0
print(&quot; The total duration is 0 for climate Dwc.&quot;)
if dicts.get(&#39;Dwd&#39;):
total_dwd=max_dwd-min_dwd
#str(total_dwd)
print(&quot;the total duration is for climate Dwd is: &quot;, total_dwd, &quot;seconds&quot;)
else:
total_dwd=0
print(&quot; The total duration is 0 for climate Dwd.&quot;)
if dicts.get(&#39;EF&#39;):
total_ef=max_ef-min_ef
#str(total_ef)
print(&quot;the total duration is for climate EF is: &quot;, total_ef, &quot;seconds&quot;)
else:
total_ef=0
print(&quot; The total duration is 0 for climate EF.&quot;)
if dicts.get(&#39;ET&#39;):
total_et=max_et-min_et
# str(total_et)
print(&quot;the total duration is for climate ET is: &quot;, total_et, &quot;seconds&quot;)
else:
total_et=0
print(&quot; The total duration is 0 for climate ET.&quot;)

time_duration={&#39;Af&#39;: (total_af), &#39;Am&#39;: (total_am), &#39;As&#39;: (total_as), &#39;Aw&#39;: (total_aw), &#39;BWk&#39;: (total_bwk)
, &#39;BWh&#39;: (total_bwh), &#39;BSk&#39;: (total_bsk), &#39;BSh&#39;: (total_bsh), &#39;Cfa&#39;: (total_cfa),
&#39;Cfb&#39;: (total_cfb), &#39;Cfc&#39;: (total_cfc),&#39;Csa&#39;: (total_csa), &#39;Csb&#39;: (total_csb),
&#39;Csc&#39;: (total_csc), &#39;Cwa&#39;: (total_cwa), &#39;Cwb&#39;: (total_cwb),&#39;Cwc&#39;:(total_cwc),
&#39;Dfa&#39;: (total_dfa), &#39;Dfb&#39;: (total_dfb), &#39;Dfc&#39;: (total_dfc), &#39;Dfd&#39;:(total_dfd), &#39;Dsa&#39;:(total_dsa),
&#39;Dsc&#39;: (total_dsc), &#39;Dsd&#39;: (total_dsd), &#39;Dwa&#39;: (total_dwa), &#39;Dwb&#39;:(total_dwb),
&#39;Dwc&#39;: (total_dwc), &#39;Dwd&#39;: (total_dwd), &#39;EF&#39;: (total_ef), &#39;ET&#39;:(total_et) }

#keys_values=time_duration.values()
new_time={str(key):str(value) for key,value in time_duration.items()}

#print(new_time)
lis=(new_time.values())
header1=new_time.keys()
with (open(&quot;C:/Users/SPANDE01/Desktop/code_t/output/Duration.csv&quot;,&quot;w&quot; )) as b_file:
writer=csv.writer(b_file )
writer.writerows([header1])
writer.writerows([lis])
b_file.close()
