<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="7.7.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.025" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="Arduino-clone">
<description>Arduino Clone pinheaders
By cl@xganon.com
http://www.xganon.com</description>
<packages>
<package name="ABK-PRO-MINI">
<description>ABK-PRO-MINI</description>
<pad name="GND2" x="-3.81" y="8.89" drill="0.8" shape="long" rot="R90"/>
<pad name="GND3" x="-1.27" y="8.89" drill="0.8" shape="long" rot="R90"/>
<pad name="VCC1" x="1.27" y="8.89" drill="0.8" shape="long" rot="R90"/>
<pad name="RX1-1" x="3.81" y="8.89" drill="0.8" shape="long" rot="R90"/>
<pad name="TX0-1" x="6.35" y="8.89" drill="0.8" shape="long" rot="R90"/>
<pad name="DTR" x="8.89" y="8.89" drill="0.8" shape="long" rot="R90"/>
<pad name="TX0" x="-5.08" y="6.35" drill="0.8" shape="long" rot="R180"/>
<pad name="RX1" x="-5.08" y="3.81" drill="0.8" shape="long" rot="R180"/>
<pad name="RST1" x="-5.08" y="1.27" drill="0.8" shape="long" rot="R180"/>
<pad name="GND1" x="-5.08" y="-1.27" drill="0.8" shape="long" rot="R180"/>
<pad name="D2" x="-5.08" y="-3.81" drill="0.8" shape="long" rot="R180"/>
<pad name="D3" x="-5.08" y="-6.35" drill="0.8" shape="long" rot="R180"/>
<pad name="D4" x="-5.08" y="-8.89" drill="0.8" shape="long" rot="R180"/>
<pad name="D5" x="-5.08" y="-11.43" drill="0.8" shape="long" rot="R180"/>
<pad name="D6" x="-5.08" y="-13.97" drill="0.8" shape="long" rot="R180"/>
<pad name="D7" x="-5.08" y="-16.51" drill="0.8" shape="long" rot="R180"/>
<pad name="D8" x="-5.08" y="-19.05" drill="0.8" shape="long" rot="R180"/>
<pad name="D9" x="-5.08" y="-21.59" drill="0.8" shape="long" rot="R180"/>
<pad name="RAW" x="10.16" y="6.35" drill="0.8" shape="long" rot="R180"/>
<pad name="GND" x="10.16" y="3.81" drill="0.8" shape="long" rot="R180"/>
<pad name="RST" x="10.16" y="1.27" drill="0.8" shape="long" rot="R180"/>
<pad name="VCC" x="10.16" y="-1.27" drill="0.8" shape="long" rot="R180"/>
<pad name="A0" x="10.16" y="-3.81" drill="0.8" shape="long" rot="R180"/>
<pad name="A1" x="10.16" y="-6.35" drill="0.8" shape="long" rot="R180"/>
<pad name="A2" x="10.16" y="-8.89" drill="0.8" shape="long" rot="R180"/>
<pad name="A3" x="10.16" y="-11.43" drill="0.8" shape="long" rot="R180"/>
<pad name="D13" x="10.16" y="-13.97" drill="0.8" shape="long" rot="R180"/>
<pad name="D12" x="10.16" y="-16.51" drill="0.8" shape="long" rot="R180"/>
<pad name="D11" x="10.16" y="-19.05" drill="0.8" shape="long" rot="R180"/>
<pad name="D10" x="10.16" y="-21.59" drill="0.8" shape="long" rot="R180"/>
<pad name="A7" x="7.62" y="-21.59" drill="0.8" shape="long" rot="R270"/>
<pad name="A6" x="5.08" y="-21.59" drill="0.8" shape="long" rot="R270"/>
<pad name="GND4" x="2.54" y="-21.59" drill="0.8" shape="long" rot="R270"/>
<pad name="A5" x="7.62" y="-2.54" drill="0.8" rot="R270"/>
<pad name="A4" x="7.62" y="-5.08" drill="0.8" rot="R270"/>
</package>
</packages>
<symbols>
<symbol name="ABK-PRO-MINI">
<description>ABK-Pro-Mini</description>
<pin name="GND3" x="-10.16" y="27.94" visible="pin" length="middle" rot="R270"/>
<pin name="GND4" x="-7.62" y="27.94" visible="pin" length="middle" rot="R270"/>
<pin name="VCC1" x="-5.08" y="27.94" visible="pin" length="middle" rot="R270"/>
<pin name="RX1-1" x="-2.54" y="27.94" visible="pin" length="middle" rot="R270"/>
<pin name="TX0-1" x="0" y="27.94" visible="pin" length="middle" rot="R270"/>
<pin name="DTR" x="2.54" y="27.94" visible="pin" length="middle" rot="R270"/>
<pin name="TX0" x="-22.86" y="12.7" visible="pin" length="middle"/>
<pin name="RX1" x="-22.86" y="10.16" visible="pin" length="middle"/>
<pin name="RST1" x="-22.86" y="7.62" visible="pin" length="middle"/>
<pin name="GND2" x="-22.86" y="5.08" visible="pin" length="middle"/>
<pin name="D2" x="-22.86" y="2.54" visible="pin" length="middle"/>
<pin name="D3" x="-22.86" y="0" visible="pin" length="middle"/>
<pin name="D4" x="-22.86" y="-2.54" visible="pin" length="middle"/>
<pin name="D5" x="-22.86" y="-5.08" visible="pin" length="middle"/>
<pin name="D6" x="-22.86" y="-7.62" visible="pin" length="middle"/>
<pin name="D7" x="-22.86" y="-10.16" visible="pin" length="middle"/>
<pin name="D8" x="-22.86" y="-12.7" visible="pin" length="middle"/>
<pin name="D9" x="-22.86" y="-15.24" visible="pin" length="middle"/>
<pin name="RAW" x="15.24" y="12.7" visible="pin" length="middle" rot="R180"/>
<pin name="GND" x="15.24" y="10.16" visible="pin" length="middle" rot="R180"/>
<pin name="RST" x="15.24" y="7.62" visible="pin" length="middle" rot="R180"/>
<pin name="VCC" x="15.24" y="5.08" visible="pin" length="middle" rot="R180"/>
<pin name="A3" x="15.24" y="2.54" visible="pin" length="middle" rot="R180"/>
<pin name="A2" x="15.24" y="0" visible="pin" length="middle" rot="R180"/>
<pin name="A1" x="15.24" y="-2.54" visible="pin" length="middle" rot="R180"/>
<pin name="A0" x="15.24" y="-5.08" visible="pin" length="middle" rot="R180"/>
<pin name="D13" x="15.24" y="-7.62" visible="pin" length="middle" rot="R180"/>
<pin name="D12" x="15.24" y="-10.16" visible="pin" length="middle" rot="R180"/>
<pin name="D11" x="15.24" y="-12.7" visible="pin" length="middle" rot="R180"/>
<pin name="D10" x="15.24" y="-15.24" visible="pin" length="middle" rot="R180"/>
<pin name="A7" x="0" y="-25.4" visible="pin" length="middle" rot="R90"/>
<pin name="A6" x="-2.54" y="-25.4" visible="pin" length="middle" rot="R90"/>
<pin name="GND1" x="-5.08" y="-25.4" visible="pin" length="middle" rot="R90"/>
<pin name="A5" x="0" y="5.08" visible="pin" length="point" rot="R90"/>
<pin name="A4" x="0" y="0" visible="pin" length="point" rot="R270"/>
<wire x1="-17.78" y1="22.86" x2="10.16" y2="22.86" width="0.254" layer="94"/>
<wire x1="10.16" y1="22.86" x2="10.16" y2="-20.32" width="0.254" layer="94"/>
<wire x1="10.16" y1="-20.32" x2="-17.78" y2="-20.32" width="0.254" layer="94"/>
<wire x1="-17.78" y1="-20.32" x2="-17.78" y2="22.86" width="0.254" layer="94"/>
<text x="-5.08" y="-7.62" size="1.778" layer="95" rot="R90">Arduino Pro Mini</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="ABK-PRO-MINI">
<description>ABK Pro-Mini Arduino Clone</description>
<gates>
<gate name="G$1" symbol="ABK-PRO-MINI" x="0" y="2.54"/>
</gates>
<devices>
<device name="" package="ABK-PRO-MINI">
<connects>
<connect gate="G$1" pin="A0" pad="A0"/>
<connect gate="G$1" pin="A1" pad="A1"/>
<connect gate="G$1" pin="A2" pad="A2"/>
<connect gate="G$1" pin="A3" pad="A3"/>
<connect gate="G$1" pin="A4" pad="A4"/>
<connect gate="G$1" pin="A5" pad="A5"/>
<connect gate="G$1" pin="A6" pad="A6"/>
<connect gate="G$1" pin="A7" pad="A7"/>
<connect gate="G$1" pin="D10" pad="D10"/>
<connect gate="G$1" pin="D11" pad="D11"/>
<connect gate="G$1" pin="D12" pad="D12"/>
<connect gate="G$1" pin="D13" pad="D13"/>
<connect gate="G$1" pin="D2" pad="D2"/>
<connect gate="G$1" pin="D3" pad="D3"/>
<connect gate="G$1" pin="D4" pad="D4"/>
<connect gate="G$1" pin="D5" pad="D5"/>
<connect gate="G$1" pin="D6" pad="D6"/>
<connect gate="G$1" pin="D7" pad="D7"/>
<connect gate="G$1" pin="D8" pad="D8"/>
<connect gate="G$1" pin="D9" pad="D9"/>
<connect gate="G$1" pin="DTR" pad="DTR"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="GND1" pad="GND4"/>
<connect gate="G$1" pin="GND2" pad="GND1"/>
<connect gate="G$1" pin="GND3" pad="GND2"/>
<connect gate="G$1" pin="GND4" pad="GND3"/>
<connect gate="G$1" pin="RAW" pad="RAW"/>
<connect gate="G$1" pin="RST" pad="RST"/>
<connect gate="G$1" pin="RST1" pad="RST1"/>
<connect gate="G$1" pin="RX1" pad="RX1"/>
<connect gate="G$1" pin="RX1-1" pad="RX1-1"/>
<connect gate="G$1" pin="TX0" pad="TX0"/>
<connect gate="G$1" pin="TX0-1" pad="TX0-1"/>
<connect gate="G$1" pin="VCC" pad="VCC"/>
<connect gate="G$1" pin="VCC1" pad="VCC1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="con-lsta">
<description>&lt;b&gt;Female Headers etc.&lt;/b&gt;&lt;p&gt;
Naming:&lt;p&gt;
FE = female&lt;p&gt;
# contacts - # rows&lt;p&gt;
W = angled&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="FE05-1">
<description>&lt;b&gt;FEMALE HEADER&lt;/b&gt;</description>
<wire x1="-6.35" y1="1.27" x2="-6.35" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="-1.27" x2="-4.064" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-4.064" y1="-1.27" x2="-3.81" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="-1.016" x2="-3.556" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-3.556" y1="-1.27" x2="-1.524" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.524" y1="-1.27" x2="-1.27" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-1.016" x2="-1.016" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.016" y1="-1.27" x2="0" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0" y1="-1.27" x2="1.016" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="1.27" y1="1.27" x2="-1.016" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-1.016" y1="1.27" x2="-1.27" y2="1.016" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="1.016" x2="-1.524" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-1.524" y1="1.27" x2="-3.556" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-3.556" y1="1.27" x2="-3.81" y2="1.016" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="1.016" x2="-4.064" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-4.064" y1="1.27" x2="-6.35" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-5.334" y1="0.762" x2="-5.334" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-5.334" y1="0.508" x2="-5.588" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-5.588" y1="0.508" x2="-5.588" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-5.588" y1="-0.508" x2="-5.334" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-5.334" y1="-0.508" x2="-5.334" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-5.334" y1="-0.762" x2="-4.826" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-4.826" y1="-0.762" x2="-4.826" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-4.826" y1="-0.508" x2="-4.572" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-4.572" y1="-0.508" x2="-4.572" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-4.572" y1="0.508" x2="-4.826" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-4.826" y1="0.508" x2="-4.826" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-4.826" y1="0.762" x2="-5.334" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-2.794" y1="0.762" x2="-2.794" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-2.794" y1="0.508" x2="-3.048" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-3.048" y1="0.508" x2="-3.048" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-3.048" y1="-0.508" x2="-2.794" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-2.794" y1="-0.508" x2="-2.794" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-2.794" y1="-0.762" x2="-2.286" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-2.286" y1="-0.762" x2="-2.286" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-2.286" y1="-0.508" x2="-2.032" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-2.032" y1="-0.508" x2="-2.032" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-2.032" y1="0.508" x2="-2.286" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-2.286" y1="0.508" x2="-2.286" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-2.286" y1="0.762" x2="-2.794" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-0.254" y1="0.762" x2="-0.254" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-0.254" y1="0.508" x2="-0.508" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-0.508" y1="0.508" x2="-0.508" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-0.508" y1="-0.508" x2="-0.254" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-0.254" y1="-0.508" x2="-0.254" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-0.254" y1="-0.762" x2="0.254" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="0.254" y1="-0.762" x2="0.254" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="0.254" y1="-0.508" x2="0.508" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="0.508" y1="-0.508" x2="0.508" y2="0.508" width="0.1524" layer="51"/>
<wire x1="0.508" y1="0.508" x2="0.254" y2="0.508" width="0.1524" layer="51"/>
<wire x1="0.254" y1="0.508" x2="0.254" y2="0.762" width="0.1524" layer="51"/>
<wire x1="0.254" y1="0.762" x2="-0.254" y2="0.762" width="0.1524" layer="51"/>
<pad name="1" x="-5.08" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="2" x="-2.54" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="3" x="0" y="0" drill="0.8128" shape="long" rot="R90"/>
<text x="-6.35" y="1.651" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-7.493" y="-0.635" size="1.27" layer="21" ratio="10">1</text>
<text x="0" y="1.651" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<rectangle x1="-5.207" y1="0.254" x2="-4.953" y2="0.762" layer="51"/>
<rectangle x1="-5.207" y1="-0.762" x2="-4.953" y2="-0.254" layer="51"/>
<rectangle x1="-2.667" y1="0.254" x2="-2.413" y2="0.762" layer="51"/>
<rectangle x1="-2.667" y1="-0.762" x2="-2.413" y2="-0.254" layer="51"/>
<rectangle x1="-0.127" y1="0.254" x2="0.127" y2="0.762" layer="51"/>
<rectangle x1="-0.127" y1="-0.762" x2="0.127" y2="-0.254" layer="51"/>
<wire x1="1.27" y1="1.27" x2="1.27" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-1.27" x2="1.016" y2="-1.27" width="0.1524" layer="21"/>
<text x="1.905" y="-0.635" size="1.27" layer="21">3</text>
</package>
<package name="FE06">
<description>&lt;b&gt;FEMALE HEADER&lt;/b&gt;</description>
<wire x1="-7.62" y1="1.27" x2="-7.62" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="-1.27" x2="-5.334" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-5.334" y1="-1.27" x2="-5.08" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-1.016" x2="-4.826" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-4.826" y1="-1.27" x2="-2.794" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-2.794" y1="-1.27" x2="-2.54" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-1.016" x2="-2.286" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="-1.27" x2="-0.254" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="-1.27" x2="0" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="0" y1="-1.016" x2="0.254" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.254" y1="-1.27" x2="2.286" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="2.286" y1="-1.27" x2="2.54" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-1.016" x2="2.794" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="2.794" y1="-1.27" x2="4.826" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="5.334" y1="-1.27" x2="7.62" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="7.62" y1="-1.27" x2="7.62" y2="1.27" width="0.1524" layer="21"/>
<wire x1="7.62" y1="1.27" x2="5.334" y2="1.27" width="0.1524" layer="21"/>
<wire x1="4.826" y1="1.27" x2="2.794" y2="1.27" width="0.1524" layer="21"/>
<wire x1="2.794" y1="1.27" x2="2.54" y2="1.016" width="0.1524" layer="21"/>
<wire x1="2.54" y1="1.016" x2="2.286" y2="1.27" width="0.1524" layer="21"/>
<wire x1="2.286" y1="1.27" x2="0.254" y2="1.27" width="0.1524" layer="21"/>
<wire x1="0.254" y1="1.27" x2="0" y2="1.016" width="0.1524" layer="21"/>
<wire x1="0" y1="1.016" x2="-0.254" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="1.27" x2="-2.286" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="1.27" x2="-2.54" y2="1.016" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="1.016" x2="-2.794" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-2.794" y1="1.27" x2="-4.826" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-4.826" y1="1.27" x2="-5.08" y2="1.016" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="1.016" x2="-5.334" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-5.334" y1="1.27" x2="-7.62" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-6.604" y1="0.762" x2="-6.604" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-6.604" y1="0.508" x2="-6.858" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-6.858" y1="0.508" x2="-6.858" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-6.858" y1="-0.508" x2="-6.604" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-6.604" y1="-0.508" x2="-6.604" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-6.604" y1="-0.762" x2="-6.096" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-6.096" y1="-0.762" x2="-6.096" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-6.096" y1="-0.508" x2="-5.842" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-5.842" y1="-0.508" x2="-5.842" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-5.842" y1="0.508" x2="-6.096" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-6.096" y1="0.508" x2="-6.096" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-6.096" y1="0.762" x2="-6.604" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-4.064" y1="0.762" x2="-4.064" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-4.064" y1="0.508" x2="-4.318" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-4.318" y1="0.508" x2="-4.318" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-4.318" y1="-0.508" x2="-4.064" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-4.064" y1="-0.508" x2="-4.064" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-4.064" y1="-0.762" x2="-3.556" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-3.556" y1="-0.762" x2="-3.556" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-3.556" y1="-0.508" x2="-3.302" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-3.302" y1="-0.508" x2="-3.302" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-3.302" y1="0.508" x2="-3.556" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-3.556" y1="0.508" x2="-3.556" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-3.556" y1="0.762" x2="-4.064" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-1.524" y1="0.762" x2="-1.524" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-1.524" y1="0.508" x2="-1.778" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-1.778" y1="0.508" x2="-1.778" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-1.778" y1="-0.508" x2="-1.524" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-1.524" y1="-0.508" x2="-1.524" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-1.524" y1="-0.762" x2="-1.016" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-1.016" y1="-0.762" x2="-1.016" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-1.016" y1="-0.508" x2="-0.762" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-0.762" y1="-0.508" x2="-0.762" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-0.762" y1="0.508" x2="-1.016" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-1.016" y1="0.508" x2="-1.016" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-1.016" y1="0.762" x2="-1.524" y2="0.762" width="0.1524" layer="51"/>
<wire x1="1.016" y1="0.762" x2="1.016" y2="0.508" width="0.1524" layer="51"/>
<wire x1="1.016" y1="0.508" x2="0.762" y2="0.508" width="0.1524" layer="51"/>
<wire x1="0.762" y1="0.508" x2="0.762" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="0.762" y1="-0.508" x2="1.016" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="1.016" y1="-0.508" x2="1.016" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="1.016" y1="-0.762" x2="1.524" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="1.524" y1="-0.762" x2="1.524" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="1.524" y1="-0.508" x2="1.778" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="1.778" y1="-0.508" x2="1.778" y2="0.508" width="0.1524" layer="51"/>
<wire x1="1.778" y1="0.508" x2="1.524" y2="0.508" width="0.1524" layer="51"/>
<wire x1="1.524" y1="0.508" x2="1.524" y2="0.762" width="0.1524" layer="51"/>
<wire x1="1.524" y1="0.762" x2="1.016" y2="0.762" width="0.1524" layer="51"/>
<wire x1="3.556" y1="0.762" x2="3.556" y2="0.508" width="0.1524" layer="51"/>
<wire x1="3.556" y1="0.508" x2="3.302" y2="0.508" width="0.1524" layer="51"/>
<wire x1="3.302" y1="0.508" x2="3.302" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="3.302" y1="-0.508" x2="3.556" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="3.556" y1="-0.508" x2="3.556" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="3.556" y1="-0.762" x2="4.064" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="4.064" y1="-0.762" x2="4.064" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="4.064" y1="-0.508" x2="4.318" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="4.318" y1="-0.508" x2="4.318" y2="0.508" width="0.1524" layer="51"/>
<wire x1="4.318" y1="0.508" x2="4.064" y2="0.508" width="0.1524" layer="51"/>
<wire x1="4.064" y1="0.508" x2="4.064" y2="0.762" width="0.1524" layer="51"/>
<wire x1="4.064" y1="0.762" x2="3.556" y2="0.762" width="0.1524" layer="51"/>
<wire x1="5.334" y1="1.27" x2="5.08" y2="1.016" width="0.1524" layer="21"/>
<wire x1="5.08" y1="1.016" x2="4.826" y2="1.27" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-1.016" x2="5.334" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="4.826" y1="-1.27" x2="5.08" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="6.096" y1="0.762" x2="6.096" y2="0.508" width="0.1524" layer="51"/>
<wire x1="6.096" y1="0.508" x2="5.842" y2="0.508" width="0.1524" layer="51"/>
<wire x1="5.842" y1="0.508" x2="5.842" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="5.842" y1="-0.508" x2="6.096" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="6.096" y1="-0.508" x2="6.096" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="6.096" y1="-0.762" x2="6.604" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="6.604" y1="-0.762" x2="6.604" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="6.604" y1="-0.508" x2="6.858" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="6.858" y1="-0.508" x2="6.858" y2="0.508" width="0.1524" layer="51"/>
<wire x1="6.858" y1="0.508" x2="6.604" y2="0.508" width="0.1524" layer="51"/>
<wire x1="6.604" y1="0.508" x2="6.604" y2="0.762" width="0.1524" layer="51"/>
<wire x1="6.604" y1="0.762" x2="6.096" y2="0.762" width="0.1524" layer="51"/>
<pad name="1" x="-6.35" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="2" x="-3.81" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="3" x="-1.27" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="4" x="1.27" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="5" x="3.81" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="6" x="6.35" y="0" drill="0.8128" shape="long" rot="R90"/>
<text x="-3.81" y="1.651" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-6.858" y="1.524" size="1.27" layer="21" ratio="10">1</text>
<text x="-7.62" y="-2.921" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<text x="5.842" y="1.524" size="1.27" layer="21" ratio="10">6</text>
<rectangle x1="-6.477" y1="0.254" x2="-6.223" y2="0.762" layer="51"/>
<rectangle x1="-6.477" y1="-0.762" x2="-6.223" y2="-0.254" layer="51"/>
<rectangle x1="-3.937" y1="0.254" x2="-3.683" y2="0.762" layer="51"/>
<rectangle x1="-3.937" y1="-0.762" x2="-3.683" y2="-0.254" layer="51"/>
<rectangle x1="-1.397" y1="0.254" x2="-1.143" y2="0.762" layer="51"/>
<rectangle x1="-1.397" y1="-0.762" x2="-1.143" y2="-0.254" layer="51"/>
<rectangle x1="1.143" y1="0.254" x2="1.397" y2="0.762" layer="51"/>
<rectangle x1="1.143" y1="-0.762" x2="1.397" y2="-0.254" layer="51"/>
<rectangle x1="3.683" y1="0.254" x2="3.937" y2="0.762" layer="51"/>
<rectangle x1="3.683" y1="-0.762" x2="3.937" y2="-0.254" layer="51"/>
<rectangle x1="6.223" y1="0.254" x2="6.477" y2="0.762" layer="51"/>
<rectangle x1="6.223" y1="-0.762" x2="6.477" y2="-0.254" layer="51"/>
</package>
<package name="FE07">
<description>&lt;b&gt;FEMALE HEADER&lt;/b&gt;</description>
<wire x1="-8.89" y1="1.27" x2="-8.89" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-8.89" y1="-1.27" x2="-6.604" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-6.604" y1="-1.27" x2="-6.35" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="-1.016" x2="-6.096" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-6.096" y1="-1.27" x2="-4.064" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-4.064" y1="-1.27" x2="-3.81" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="-1.016" x2="-3.556" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-3.556" y1="-1.27" x2="-1.524" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.524" y1="-1.27" x2="-1.27" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-1.016" x2="-1.016" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.016" y1="-1.27" x2="1.016" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="1.016" y1="-1.27" x2="1.27" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-1.016" x2="1.524" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="8.89" y1="-1.27" x2="8.89" y2="1.27" width="0.1524" layer="21"/>
<wire x1="1.524" y1="1.27" x2="1.27" y2="1.016" width="0.1524" layer="21"/>
<wire x1="1.27" y1="1.016" x2="1.016" y2="1.27" width="0.1524" layer="21"/>
<wire x1="1.016" y1="1.27" x2="-1.016" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-1.016" y1="1.27" x2="-1.27" y2="1.016" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="1.016" x2="-1.524" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-1.524" y1="1.27" x2="-3.556" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-3.556" y1="1.27" x2="-3.81" y2="1.016" width="0.1524" layer="21"/>
<wire x1="-3.81" y1="1.016" x2="-4.064" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-4.064" y1="1.27" x2="-6.096" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-6.096" y1="1.27" x2="-6.35" y2="1.016" width="0.1524" layer="21"/>
<wire x1="-6.35" y1="1.016" x2="-6.604" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-6.604" y1="1.27" x2="-8.89" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-7.874" y1="0.762" x2="-7.874" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-7.874" y1="0.508" x2="-8.128" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-8.128" y1="0.508" x2="-8.128" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-8.128" y1="-0.508" x2="-7.874" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-7.874" y1="-0.508" x2="-7.874" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-7.874" y1="-0.762" x2="-7.366" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-7.366" y1="-0.762" x2="-7.366" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-7.366" y1="-0.508" x2="-7.112" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-7.112" y1="-0.508" x2="-7.112" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-7.112" y1="0.508" x2="-7.366" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-7.366" y1="0.508" x2="-7.366" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-7.366" y1="0.762" x2="-7.874" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-5.334" y1="0.762" x2="-5.334" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-5.334" y1="0.508" x2="-5.588" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-5.588" y1="0.508" x2="-5.588" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-5.588" y1="-0.508" x2="-5.334" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-5.334" y1="-0.508" x2="-5.334" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-5.334" y1="-0.762" x2="-4.826" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-4.826" y1="-0.762" x2="-4.826" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-4.826" y1="-0.508" x2="-4.572" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-4.572" y1="-0.508" x2="-4.572" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-4.572" y1="0.508" x2="-4.826" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-4.826" y1="0.508" x2="-4.826" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-4.826" y1="0.762" x2="-5.334" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-2.794" y1="0.762" x2="-2.794" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-2.794" y1="0.508" x2="-3.048" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-3.048" y1="0.508" x2="-3.048" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-3.048" y1="-0.508" x2="-2.794" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-2.794" y1="-0.508" x2="-2.794" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-2.794" y1="-0.762" x2="-2.286" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-2.286" y1="-0.762" x2="-2.286" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-2.286" y1="-0.508" x2="-2.032" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-2.032" y1="-0.508" x2="-2.032" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-2.032" y1="0.508" x2="-2.286" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-2.286" y1="0.508" x2="-2.286" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-2.286" y1="0.762" x2="-2.794" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-0.254" y1="0.762" x2="-0.254" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-0.254" y1="0.508" x2="-0.508" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-0.508" y1="0.508" x2="-0.508" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-0.508" y1="-0.508" x2="-0.254" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-0.254" y1="-0.508" x2="-0.254" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-0.254" y1="-0.762" x2="0.254" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="0.254" y1="-0.762" x2="0.254" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="0.254" y1="-0.508" x2="0.508" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="0.508" y1="-0.508" x2="0.508" y2="0.508" width="0.1524" layer="51"/>
<wire x1="0.508" y1="0.508" x2="0.254" y2="0.508" width="0.1524" layer="51"/>
<wire x1="0.254" y1="0.508" x2="0.254" y2="0.762" width="0.1524" layer="51"/>
<wire x1="0.254" y1="0.762" x2="-0.254" y2="0.762" width="0.1524" layer="51"/>
<wire x1="2.286" y1="0.762" x2="2.286" y2="0.508" width="0.1524" layer="51"/>
<wire x1="2.286" y1="0.508" x2="2.032" y2="0.508" width="0.1524" layer="51"/>
<wire x1="2.032" y1="0.508" x2="2.032" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="2.032" y1="-0.508" x2="2.286" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="2.286" y1="-0.508" x2="2.286" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="2.286" y1="-0.762" x2="2.794" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="2.794" y1="-0.762" x2="2.794" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="2.794" y1="-0.508" x2="3.048" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="3.048" y1="-0.508" x2="3.048" y2="0.508" width="0.1524" layer="51"/>
<wire x1="3.048" y1="0.508" x2="2.794" y2="0.508" width="0.1524" layer="51"/>
<wire x1="2.794" y1="0.508" x2="2.794" y2="0.762" width="0.1524" layer="51"/>
<wire x1="2.794" y1="0.762" x2="2.286" y2="0.762" width="0.1524" layer="51"/>
<wire x1="1.524" y1="-1.27" x2="3.556" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="3.556" y1="-1.27" x2="3.81" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="3.81" y1="-1.016" x2="4.064" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="4.064" y1="-1.27" x2="6.096" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="6.096" y1="-1.27" x2="6.35" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="6.35" y1="-1.016" x2="6.604" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="6.604" y1="1.27" x2="6.35" y2="1.016" width="0.1524" layer="21"/>
<wire x1="6.35" y1="1.016" x2="6.096" y2="1.27" width="0.1524" layer="21"/>
<wire x1="6.096" y1="1.27" x2="4.064" y2="1.27" width="0.1524" layer="21"/>
<wire x1="4.064" y1="1.27" x2="3.81" y2="1.016" width="0.1524" layer="21"/>
<wire x1="3.81" y1="1.016" x2="3.556" y2="1.27" width="0.1524" layer="21"/>
<wire x1="3.556" y1="1.27" x2="1.524" y2="1.27" width="0.1524" layer="21"/>
<wire x1="4.826" y1="0.762" x2="4.826" y2="0.508" width="0.1524" layer="51"/>
<wire x1="4.826" y1="0.508" x2="4.572" y2="0.508" width="0.1524" layer="51"/>
<wire x1="4.572" y1="0.508" x2="4.572" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="4.572" y1="-0.508" x2="4.826" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="4.826" y1="-0.508" x2="4.826" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="4.826" y1="-0.762" x2="5.334" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="5.334" y1="-0.762" x2="5.334" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="5.334" y1="-0.508" x2="5.588" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="5.588" y1="-0.508" x2="5.588" y2="0.508" width="0.1524" layer="51"/>
<wire x1="5.588" y1="0.508" x2="5.334" y2="0.508" width="0.1524" layer="51"/>
<wire x1="5.334" y1="0.508" x2="5.334" y2="0.762" width="0.1524" layer="51"/>
<wire x1="5.334" y1="0.762" x2="4.826" y2="0.762" width="0.1524" layer="51"/>
<wire x1="7.366" y1="0.762" x2="7.366" y2="0.508" width="0.1524" layer="51"/>
<wire x1="7.366" y1="0.508" x2="7.112" y2="0.508" width="0.1524" layer="51"/>
<wire x1="7.112" y1="0.508" x2="7.112" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="7.112" y1="-0.508" x2="7.366" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="7.366" y1="-0.508" x2="7.366" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="7.366" y1="-0.762" x2="7.874" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="7.874" y1="-0.762" x2="7.874" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="7.874" y1="-0.508" x2="8.128" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="8.128" y1="-0.508" x2="8.128" y2="0.508" width="0.1524" layer="51"/>
<wire x1="8.128" y1="0.508" x2="7.874" y2="0.508" width="0.1524" layer="51"/>
<wire x1="7.874" y1="0.508" x2="7.874" y2="0.762" width="0.1524" layer="51"/>
<wire x1="7.874" y1="0.762" x2="7.366" y2="0.762" width="0.1524" layer="51"/>
<wire x1="8.89" y1="1.27" x2="6.604" y2="1.27" width="0.1524" layer="21"/>
<wire x1="6.604" y1="-1.27" x2="8.89" y2="-1.27" width="0.1524" layer="21"/>
<pad name="1" x="-7.62" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="2" x="-5.08" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="3" x="-2.54" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="4" x="0" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="5" x="2.54" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="6" x="5.08" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="7" x="7.62" y="0" drill="0.8128" shape="long" rot="R90"/>
<text x="-5.08" y="1.651" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-8.128" y="1.524" size="1.27" layer="21" ratio="10">1</text>
<text x="-7.62" y="-2.921" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<text x="7.112" y="1.524" size="1.27" layer="21" ratio="10">7</text>
<rectangle x1="-7.747" y1="0.254" x2="-7.493" y2="0.762" layer="51"/>
<rectangle x1="-7.747" y1="-0.762" x2="-7.493" y2="-0.254" layer="51"/>
<rectangle x1="-5.207" y1="0.254" x2="-4.953" y2="0.762" layer="51"/>
<rectangle x1="-5.207" y1="-0.762" x2="-4.953" y2="-0.254" layer="51"/>
<rectangle x1="-2.667" y1="0.254" x2="-2.413" y2="0.762" layer="51"/>
<rectangle x1="-2.667" y1="-0.762" x2="-2.413" y2="-0.254" layer="51"/>
<rectangle x1="-0.127" y1="0.254" x2="0.127" y2="0.762" layer="51"/>
<rectangle x1="-0.127" y1="-0.762" x2="0.127" y2="-0.254" layer="51"/>
<rectangle x1="2.413" y1="0.254" x2="2.667" y2="0.762" layer="51"/>
<rectangle x1="2.413" y1="-0.762" x2="2.667" y2="-0.254" layer="51"/>
<rectangle x1="4.953" y1="0.254" x2="5.207" y2="0.762" layer="51"/>
<rectangle x1="4.953" y1="-0.762" x2="5.207" y2="-0.254" layer="51"/>
<rectangle x1="7.493" y1="0.254" x2="7.747" y2="0.762" layer="51"/>
<rectangle x1="7.493" y1="-0.762" x2="7.747" y2="-0.254" layer="51"/>
</package>
<package name="FE08">
<description>&lt;b&gt;FEMALE HEADER&lt;/b&gt;</description>
<wire x1="-10.16" y1="1.27" x2="-10.16" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-10.16" y1="-1.27" x2="-7.874" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-7.874" y1="-1.27" x2="-7.62" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="-1.016" x2="-7.366" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-7.366" y1="-1.27" x2="-5.334" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-5.334" y1="-1.27" x2="-5.08" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-1.016" x2="-4.826" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-4.826" y1="-1.27" x2="-2.794" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-2.794" y1="-1.27" x2="-2.54" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="-1.016" x2="-2.286" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="-1.27" x2="-0.254" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="-1.27" x2="0" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="0" y1="-1.016" x2="0.254" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.254" y1="1.27" x2="0" y2="1.016" width="0.1524" layer="21"/>
<wire x1="0" y1="1.016" x2="-0.254" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-0.254" y1="1.27" x2="-2.286" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="1.27" x2="-2.54" y2="1.016" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="1.016" x2="-2.794" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-2.794" y1="1.27" x2="-4.826" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-4.826" y1="1.27" x2="-5.08" y2="1.016" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="1.016" x2="-5.334" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-5.334" y1="1.27" x2="-7.366" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-7.366" y1="1.27" x2="-7.62" y2="1.016" width="0.1524" layer="21"/>
<wire x1="-7.62" y1="1.016" x2="-7.874" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-7.874" y1="1.27" x2="-10.16" y2="1.27" width="0.1524" layer="21"/>
<wire x1="-9.144" y1="0.762" x2="-9.144" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-9.144" y1="0.508" x2="-9.398" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-9.398" y1="0.508" x2="-9.398" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-9.398" y1="-0.508" x2="-9.144" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-9.144" y1="-0.508" x2="-9.144" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-9.144" y1="-0.762" x2="-8.636" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-8.636" y1="-0.762" x2="-8.636" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-8.636" y1="-0.508" x2="-8.382" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-8.382" y1="-0.508" x2="-8.382" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-8.382" y1="0.508" x2="-8.636" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-8.636" y1="0.508" x2="-8.636" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-8.636" y1="0.762" x2="-9.144" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-6.604" y1="0.762" x2="-6.604" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-6.604" y1="0.508" x2="-6.858" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-6.858" y1="0.508" x2="-6.858" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-6.858" y1="-0.508" x2="-6.604" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-6.604" y1="-0.508" x2="-6.604" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-6.604" y1="-0.762" x2="-6.096" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-6.096" y1="-0.762" x2="-6.096" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-6.096" y1="-0.508" x2="-5.842" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-5.842" y1="-0.508" x2="-5.842" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-5.842" y1="0.508" x2="-6.096" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-6.096" y1="0.508" x2="-6.096" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-6.096" y1="0.762" x2="-6.604" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-4.064" y1="0.762" x2="-4.064" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-4.064" y1="0.508" x2="-4.318" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-4.318" y1="0.508" x2="-4.318" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-4.318" y1="-0.508" x2="-4.064" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-4.064" y1="-0.508" x2="-4.064" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-4.064" y1="-0.762" x2="-3.556" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-3.556" y1="-0.762" x2="-3.556" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-3.556" y1="-0.508" x2="-3.302" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-3.302" y1="-0.508" x2="-3.302" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-3.302" y1="0.508" x2="-3.556" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-3.556" y1="0.508" x2="-3.556" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-3.556" y1="0.762" x2="-4.064" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-1.524" y1="0.762" x2="-1.524" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-1.524" y1="0.508" x2="-1.778" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-1.778" y1="0.508" x2="-1.778" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-1.778" y1="-0.508" x2="-1.524" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-1.524" y1="-0.508" x2="-1.524" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-1.524" y1="-0.762" x2="-1.016" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-1.016" y1="-0.762" x2="-1.016" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-1.016" y1="-0.508" x2="-0.762" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-0.762" y1="-0.508" x2="-0.762" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-0.762" y1="0.508" x2="-1.016" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-1.016" y1="0.508" x2="-1.016" y2="0.762" width="0.1524" layer="51"/>
<wire x1="-1.016" y1="0.762" x2="-1.524" y2="0.762" width="0.1524" layer="51"/>
<wire x1="1.016" y1="0.762" x2="1.016" y2="0.508" width="0.1524" layer="51"/>
<wire x1="1.016" y1="0.508" x2="0.762" y2="0.508" width="0.1524" layer="51"/>
<wire x1="0.762" y1="0.508" x2="0.762" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="0.762" y1="-0.508" x2="1.016" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="1.016" y1="-0.508" x2="1.016" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="1.016" y1="-0.762" x2="1.524" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="1.524" y1="-0.762" x2="1.524" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="1.524" y1="-0.508" x2="1.778" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="1.778" y1="-0.508" x2="1.778" y2="0.508" width="0.1524" layer="51"/>
<wire x1="1.778" y1="0.508" x2="1.524" y2="0.508" width="0.1524" layer="51"/>
<wire x1="1.524" y1="0.508" x2="1.524" y2="0.762" width="0.1524" layer="51"/>
<wire x1="1.524" y1="0.762" x2="1.016" y2="0.762" width="0.1524" layer="51"/>
<wire x1="0.254" y1="-1.27" x2="2.286" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="2.286" y1="-1.27" x2="2.54" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="2.54" y1="-1.016" x2="2.794" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="2.794" y1="-1.27" x2="4.826" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="4.826" y1="-1.27" x2="5.08" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-1.016" x2="5.334" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="5.334" y1="1.27" x2="5.08" y2="1.016" width="0.1524" layer="21"/>
<wire x1="5.08" y1="1.016" x2="4.826" y2="1.27" width="0.1524" layer="21"/>
<wire x1="4.826" y1="1.27" x2="2.794" y2="1.27" width="0.1524" layer="21"/>
<wire x1="2.794" y1="1.27" x2="2.54" y2="1.016" width="0.1524" layer="21"/>
<wire x1="2.54" y1="1.016" x2="2.286" y2="1.27" width="0.1524" layer="21"/>
<wire x1="2.286" y1="1.27" x2="0.254" y2="1.27" width="0.1524" layer="21"/>
<wire x1="3.556" y1="0.762" x2="3.556" y2="0.508" width="0.1524" layer="51"/>
<wire x1="3.556" y1="0.508" x2="3.302" y2="0.508" width="0.1524" layer="51"/>
<wire x1="3.302" y1="0.508" x2="3.302" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="3.302" y1="-0.508" x2="3.556" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="3.556" y1="-0.508" x2="3.556" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="3.556" y1="-0.762" x2="4.064" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="4.064" y1="-0.762" x2="4.064" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="4.064" y1="-0.508" x2="4.318" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="4.318" y1="-0.508" x2="4.318" y2="0.508" width="0.1524" layer="51"/>
<wire x1="4.318" y1="0.508" x2="4.064" y2="0.508" width="0.1524" layer="51"/>
<wire x1="4.064" y1="0.508" x2="4.064" y2="0.762" width="0.1524" layer="51"/>
<wire x1="4.064" y1="0.762" x2="3.556" y2="0.762" width="0.1524" layer="51"/>
<wire x1="6.096" y1="0.762" x2="6.096" y2="0.508" width="0.1524" layer="51"/>
<wire x1="6.096" y1="0.508" x2="5.842" y2="0.508" width="0.1524" layer="51"/>
<wire x1="5.842" y1="0.508" x2="5.842" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="5.842" y1="-0.508" x2="6.096" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="6.096" y1="-0.508" x2="6.096" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="6.096" y1="-0.762" x2="6.604" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="6.604" y1="-0.762" x2="6.604" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="6.604" y1="-0.508" x2="6.858" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="6.858" y1="-0.508" x2="6.858" y2="0.508" width="0.1524" layer="51"/>
<wire x1="6.858" y1="0.508" x2="6.604" y2="0.508" width="0.1524" layer="51"/>
<wire x1="6.604" y1="0.508" x2="6.604" y2="0.762" width="0.1524" layer="51"/>
<wire x1="6.604" y1="0.762" x2="6.096" y2="0.762" width="0.1524" layer="51"/>
<wire x1="10.16" y1="1.27" x2="7.874" y2="1.27" width="0.1524" layer="21"/>
<wire x1="10.16" y1="-1.27" x2="10.16" y2="1.27" width="0.1524" layer="21"/>
<wire x1="7.874" y1="-1.27" x2="10.16" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="7.62" y1="1.016" x2="7.366" y2="1.27" width="0.1524" layer="21"/>
<wire x1="7.874" y1="1.27" x2="7.62" y2="1.016" width="0.1524" layer="21"/>
<wire x1="7.366" y1="1.27" x2="5.334" y2="1.27" width="0.1524" layer="21"/>
<wire x1="7.62" y1="-1.016" x2="7.874" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="7.366" y1="-1.27" x2="7.62" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="5.334" y1="-1.27" x2="7.366" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="8.636" y1="0.762" x2="8.636" y2="0.508" width="0.1524" layer="51"/>
<wire x1="8.636" y1="0.508" x2="8.382" y2="0.508" width="0.1524" layer="51"/>
<wire x1="8.382" y1="0.508" x2="8.382" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="8.382" y1="-0.508" x2="8.636" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="8.636" y1="-0.508" x2="8.636" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="8.636" y1="-0.762" x2="9.144" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="9.144" y1="-0.762" x2="9.144" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="9.144" y1="-0.508" x2="9.398" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="9.398" y1="-0.508" x2="9.398" y2="0.508" width="0.1524" layer="51"/>
<wire x1="9.398" y1="0.508" x2="9.144" y2="0.508" width="0.1524" layer="51"/>
<wire x1="9.144" y1="0.508" x2="9.144" y2="0.762" width="0.1524" layer="51"/>
<wire x1="9.144" y1="0.762" x2="8.636" y2="0.762" width="0.1524" layer="51"/>
<pad name="1" x="-8.89" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="2" x="-6.35" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="3" x="-3.81" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="4" x="-1.27" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="5" x="1.27" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="6" x="3.81" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="7" x="6.35" y="0" drill="0.8128" shape="long" rot="R90"/>
<pad name="8" x="8.89" y="0" drill="0.8128" shape="long" rot="R90"/>
<text x="-6.35" y="1.651" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-9.398" y="1.524" size="1.27" layer="21" ratio="10">1</text>
<text x="-10.16" y="-2.921" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<text x="8.382" y="1.524" size="1.27" layer="21" ratio="10">8</text>
<rectangle x1="-9.017" y1="0.254" x2="-8.763" y2="0.762" layer="51"/>
<rectangle x1="-9.017" y1="-0.762" x2="-8.763" y2="-0.254" layer="51"/>
<rectangle x1="-6.477" y1="0.254" x2="-6.223" y2="0.762" layer="51"/>
<rectangle x1="-6.477" y1="-0.762" x2="-6.223" y2="-0.254" layer="51"/>
<rectangle x1="-3.937" y1="0.254" x2="-3.683" y2="0.762" layer="51"/>
<rectangle x1="-3.937" y1="-0.762" x2="-3.683" y2="-0.254" layer="51"/>
<rectangle x1="-1.397" y1="0.254" x2="-1.143" y2="0.762" layer="51"/>
<rectangle x1="-1.397" y1="-0.762" x2="-1.143" y2="-0.254" layer="51"/>
<rectangle x1="1.143" y1="0.254" x2="1.397" y2="0.762" layer="51"/>
<rectangle x1="1.143" y1="-0.762" x2="1.397" y2="-0.254" layer="51"/>
<rectangle x1="3.683" y1="0.254" x2="3.937" y2="0.762" layer="51"/>
<rectangle x1="3.683" y1="-0.762" x2="3.937" y2="-0.254" layer="51"/>
<rectangle x1="6.223" y1="0.254" x2="6.477" y2="0.762" layer="51"/>
<rectangle x1="6.223" y1="-0.762" x2="6.477" y2="-0.254" layer="51"/>
<rectangle x1="8.763" y1="0.254" x2="9.017" y2="0.762" layer="51"/>
<rectangle x1="8.763" y1="-0.762" x2="9.017" y2="-0.254" layer="51"/>
</package>
<package name="FE02">
<wire x1="0" y1="0" x2="0" y2="2.54" width="0.127" layer="21"/>
<pad name="1" x="1.27" y="1.27" drill="0.8" shape="long" rot="R90"/>
<pad name="2" x="3.81" y="1.27" drill="0.8" shape="long" rot="R90"/>
<wire x1="0" y1="2.54" x2="2.2225" y2="2.54" width="0.127" layer="21"/>
<wire x1="2.2225" y1="2.54" x2="2.54" y2="2.2225" width="0.127" layer="21"/>
<wire x1="2.54" y1="2.2225" x2="2.8575" y2="2.54" width="0.127" layer="21"/>
<wire x1="2.8575" y1="2.54" x2="5.08" y2="2.54" width="0.127" layer="21"/>
<wire x1="5.08" y1="2.54" x2="5.08" y2="0" width="0.127" layer="21"/>
<wire x1="5.08" y1="0" x2="2.8575" y2="0" width="0.127" layer="21"/>
<wire x1="2.8575" y1="0" x2="2.54" y2="0.3175" width="0.127" layer="21"/>
<wire x1="2.54" y1="0.3175" x2="2.2225" y2="0" width="0.127" layer="21"/>
<wire x1="2.2225" y1="0" x2="0" y2="0" width="0.127" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="FE05">
<wire x1="-1.27" y1="2.54" x2="-1.27" y2="-7.62" width="0.254" layer="94"/>
<wire x1="-1.27" y1="-7.62" x2="-6.35" y2="-7.62" width="0.254" layer="94"/>
<wire x1="-6.35" y1="-7.62" x2="-6.35" y2="2.54" width="0.254" layer="94"/>
<wire x1="-3.175" y1="0.635" x2="-3.175" y2="-0.635" width="0.254" layer="94" curve="-180"/>
<wire x1="-3.175" y1="-1.905" x2="-3.175" y2="-3.175" width="0.254" layer="94" curve="-180"/>
<wire x1="-3.175" y1="-4.445" x2="-3.175" y2="-5.715" width="0.254" layer="94" curve="-180"/>
<wire x1="-1.27" y1="2.54" x2="-6.35" y2="2.54" width="0.254" layer="94"/>
<pin name="SIGNAL" x="2.54" y="-5.08" length="middle" rot="R180"/>
<pin name="VCC" x="2.54" y="-2.54" length="middle" rot="R180"/>
<pin name="GND" x="2.54" y="0" length="middle" rot="R180"/>
<text x="-6.35" y="3.175" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-10.16" size="1.778" layer="95">&gt;VALUE</text>
</symbol>
<symbol name="FE06-1">
<wire x1="3.81" y1="-7.62" x2="-1.27" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="1.905" y1="0.635" x2="1.905" y2="-0.635" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="-1.905" x2="1.905" y2="-3.175" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="-4.445" x2="1.905" y2="-5.715" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="-1.27" y1="10.16" x2="-1.27" y2="-7.62" width="0.4064" layer="94"/>
<wire x1="3.81" y1="-7.62" x2="3.81" y2="10.16" width="0.4064" layer="94"/>
<wire x1="-1.27" y1="10.16" x2="3.81" y2="10.16" width="0.4064" layer="94"/>
<wire x1="1.905" y1="5.715" x2="1.905" y2="4.445" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="3.175" x2="1.905" y2="1.905" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="8.255" x2="1.905" y2="6.985" width="0.254" layer="94" curve="-180" cap="flat"/>
<text x="-1.27" y="-10.16" size="1.778" layer="96">&gt;VALUE</text>
<text x="-1.27" y="10.922" size="1.778" layer="95">&gt;NAME</text>
<pin name="1" x="7.62" y="-5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="2" x="7.62" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="3" x="7.62" y="0" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="4" x="7.62" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="5" x="7.62" y="5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="6" x="7.62" y="7.62" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
</symbol>
<symbol name="FE07-1">
<wire x1="3.81" y1="-10.16" x2="-1.27" y2="-10.16" width="0.4064" layer="94"/>
<wire x1="1.905" y1="-1.905" x2="1.905" y2="-3.175" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="-4.445" x2="1.905" y2="-5.715" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="-6.985" x2="1.905" y2="-8.255" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="-1.27" y1="10.16" x2="-1.27" y2="-10.16" width="0.4064" layer="94"/>
<wire x1="3.81" y1="-10.16" x2="3.81" y2="10.16" width="0.4064" layer="94"/>
<wire x1="-1.27" y1="10.16" x2="3.81" y2="10.16" width="0.4064" layer="94"/>
<wire x1="1.905" y1="3.175" x2="1.905" y2="1.905" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="0.635" x2="1.905" y2="-0.635" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="5.715" x2="1.905" y2="4.445" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="8.255" x2="1.905" y2="6.985" width="0.254" layer="94" curve="-180" cap="flat"/>
<text x="-1.27" y="-12.7" size="1.778" layer="96">&gt;VALUE</text>
<text x="-1.27" y="10.922" size="1.778" layer="95">&gt;NAME</text>
<pin name="1" x="7.62" y="-7.62" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="2" x="7.62" y="-5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="3" x="7.62" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="4" x="7.62" y="0" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="5" x="7.62" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="6" x="7.62" y="5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="7" x="7.62" y="7.62" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
</symbol>
<symbol name="FE08-1">
<wire x1="3.81" y1="-10.16" x2="-1.27" y2="-10.16" width="0.4064" layer="94"/>
<wire x1="1.905" y1="-1.905" x2="1.905" y2="-3.175" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="-4.445" x2="1.905" y2="-5.715" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="-6.985" x2="1.905" y2="-8.255" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="3.175" x2="1.905" y2="1.905" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="0.635" x2="1.905" y2="-0.635" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="10.795" x2="1.905" y2="9.525" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="8.255" x2="1.905" y2="6.985" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="1.905" y1="5.715" x2="1.905" y2="4.445" width="0.254" layer="94" curve="-180" cap="flat"/>
<wire x1="-1.27" y1="12.7" x2="-1.27" y2="-10.16" width="0.4064" layer="94"/>
<wire x1="3.81" y1="-10.16" x2="3.81" y2="12.7" width="0.4064" layer="94"/>
<wire x1="-1.27" y1="12.7" x2="3.81" y2="12.7" width="0.4064" layer="94"/>
<text x="-1.27" y="-12.7" size="1.778" layer="96">&gt;VALUE</text>
<text x="-1.27" y="13.462" size="1.778" layer="95">&gt;NAME</text>
<pin name="1" x="7.62" y="-7.62" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="2" x="7.62" y="-5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="3" x="7.62" y="-2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="4" x="7.62" y="0" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="5" x="7.62" y="2.54" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="6" x="7.62" y="5.08" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="7" x="7.62" y="7.62" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
<pin name="8" x="7.62" y="10.16" visible="pad" length="middle" direction="pas" swaplevel="1" rot="R180"/>
</symbol>
<symbol name="FE02">
<wire x1="0" y1="0" x2="0" y2="7.62" width="0.254" layer="94"/>
<wire x1="0" y1="7.62" x2="5.08" y2="7.62" width="0.254" layer="94"/>
<wire x1="5.08" y1="7.62" x2="5.08" y2="0" width="0.254" layer="94"/>
<wire x1="5.08" y1="0" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="3.175" y1="5.715" x2="3.175" y2="4.445" width="0.254" layer="94" curve="-180"/>
<wire x1="3.175" y1="3.175" x2="3.175" y2="1.905" width="0.254" layer="94" curve="-180"/>
<pin name="P$1" x="8.89" y="2.54" length="middle" rot="R180"/>
<pin name="P$2" x="8.89" y="5.08" length="middle" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="FE05-1" prefix="SV" uservalue="yes">
<description>&lt;b&gt;FEMALE HEADER&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="FE05" x="5.08" y="2.54"/>
</gates>
<devices>
<device name="" package="FE05-1">
<connects>
<connect gate="G$1" pin="GND" pad="3"/>
<connect gate="G$1" pin="SIGNAL" pad="1"/>
<connect gate="G$1" pin="VCC" pad="2"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="FE06-1" prefix="SV" uservalue="yes">
<description>&lt;b&gt;FEMALE HEADER&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="FE06-1" x="0" y="0"/>
</gates>
<devices>
<device name="" package="FE06">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="FE07-1" prefix="SV" uservalue="yes">
<description>&lt;b&gt;FEMALE HEADER&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="FE07-1" x="0" y="0"/>
</gates>
<devices>
<device name="" package="FE07">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="FE08-1" prefix="SV" uservalue="yes">
<description>&lt;b&gt;FEMALE HEADER&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="FE08-1" x="0" y="0"/>
</gates>
<devices>
<device name="" package="FE08">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="FE02">
<gates>
<gate name="G$1" symbol="FE02" x="0" y="0"/>
</gates>
<devices>
<device name="" package="FE02">
<connects>
<connect gate="G$1" pin="P$1" pad="1"/>
<connect gate="G$1" pin="P$2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply1">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
 GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
 Please keep in mind, that these devices are necessary for the
 automatic wiring of the supply signals.&lt;p&gt;
 The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
 In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
 &lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="VCC">
<wire x1="1.27" y1="-1.905" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="-1.905" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="VCC" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
<symbol name="GND">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="VCC" prefix="P+">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="VCC" symbol="VCC" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="GND" prefix="GND">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="Power Supply">
<packages>
<package name="ROWER_SUPPLY">
<pad name="1" x="1.5" y="1.5" drill="0.8" diameter="1.5"/>
<pad name="2" x="4.04" y="1.5" drill="0.8" diameter="1.5"/>
<pad name="5" x="1.5" y="20.2" drill="0.8" diameter="1.5"/>
<pad name="6" x="4.04" y="20.2" drill="0.8" diameter="1.5"/>
<pad name="7" x="12.7" y="20.2" drill="0.8" shape="square"/>
<pad name="8" x="15.24" y="20.2" drill="0.8" shape="square"/>
<pad name="3" x="12.7" y="1.5" drill="0.8" shape="square"/>
<pad name="4" x="15.24" y="1.5" drill="0.8" shape="square"/>
<wire x1="0" y1="0" x2="0" y2="21.7" width="0.127" layer="21"/>
<wire x1="0" y1="21.7" x2="17" y2="21.7" width="0.127" layer="21"/>
<wire x1="17" y1="21.7" x2="17" y2="0" width="0.127" layer="21"/>
<wire x1="17" y1="0" x2="0" y2="0" width="0.127" layer="21"/>
<text x="2" y="3" size="1.27" layer="21">IN-</text>
<text x="13" y="3" size="1.27" layer="21">IN+</text>
<text x="1" y="17" size="1.27" layer="21">OUT-</text>
<text x="12" y="17" size="1.27" layer="21">OUT+</text>
</package>
</packages>
<symbols>
<symbol name="POWER_SUPPLY">
<wire x1="0" y1="0" x2="0" y2="9.525" width="0.254" layer="94"/>
<wire x1="15.24" y1="9.525" x2="15.24" y2="0" width="0.254" layer="94"/>
<wire x1="15.24" y1="0" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="3.175" y1="1.905" x2="1.905" y2="1.905" width="0.254" layer="94" curve="-180"/>
<wire x1="5.715" y1="1.905" x2="4.445" y2="1.905" width="0.254" layer="94" curve="-180"/>
<wire x1="13.335" y1="1.905" x2="12.065" y2="1.905" width="0.254" layer="94" curve="-180"/>
<wire x1="10.795" y1="1.905" x2="9.525" y2="1.905" width="0.254" layer="94" curve="-180"/>
<wire x1="1.905" y1="7.62" x2="3.175" y2="7.62" width="0.254" layer="94" curve="-180"/>
<wire x1="4.445" y1="7.62" x2="5.715" y2="7.62" width="0.254" layer="94" curve="-180"/>
<wire x1="9.525" y1="7.62" x2="10.795" y2="7.62" width="0.254" layer="94" curve="-180"/>
<wire x1="12.065" y1="7.62" x2="13.335" y2="7.62" width="0.254" layer="94" curve="-180"/>
<pin name="1" x="2.54" y="-3.81" length="middle" rot="R90"/>
<pin name="2" x="5.08" y="-3.81" length="middle" rot="R90"/>
<pin name="3" x="10.16" y="-3.81" length="middle" rot="R90"/>
<pin name="4" x="12.7" y="-3.81" length="middle" rot="R90"/>
<pin name="5" x="2.54" y="13.335" length="middle" rot="R270"/>
<pin name="6" x="5.08" y="13.335" length="middle" rot="R270"/>
<pin name="7" x="10.16" y="13.335" length="middle" rot="R270"/>
<pin name="8" x="12.7" y="13.335" length="middle" rot="R270"/>
<wire x1="0" y1="9.525" x2="15.24" y2="9.525" width="0.254" layer="94"/>
<text x="0.635" y="-3.175" size="1.27" layer="95" rot="R90">IN-</text>
<text x="15.875" y="-3.175" size="1.27" layer="95" rot="R90">IN+</text>
<text x="0.635" y="10.795" size="1.27" layer="95" rot="R90">OUT-</text>
<text x="15.875" y="10.795" size="1.27" layer="95" rot="R90">OUT+</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="ROWER_SUPPLY">
<gates>
<gate name="G$1" symbol="POWER_SUPPLY" x="-7.62" y="-5.08"/>
</gates>
<devices>
<device name="" package="ROWER_SUPPLY">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="2018">
<packages>
<package name="2018">
<pad name="P$2" x="0" y="0" drill="1.5" diameter="3"/>
</package>
</packages>
<symbols>
<symbol name="2018">
<wire x1="0" y1="0" x2="0" y2="2.54" width="0.254" layer="94"/>
<wire x1="0" y1="2.54" x2="2.54" y2="2.54" width="0.254" layer="94"/>
<wire x1="2.54" y1="2.54" x2="2.54" y2="0" width="0.254" layer="94"/>
<wire x1="2.54" y1="0" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0.635" y1="1.27" x2="1.905" y2="1.27" width="0.254" layer="94" curve="-180"/>
<pin name="P$1" x="1.27" y="6.985" length="middle" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="2018">
<gates>
<gate name="G$1" symbol="2018" x="0" y="0"/>
</gates>
<devices>
<device name="" package="2018">
<connects>
<connect gate="G$1" pin="P$1" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="330">
<packages>
<package name="330">
<pad name="P$1" x="0" y="0" drill="0.5"/>
<pad name="P$2" x="15" y="0" drill="0.5"/>
<wire x1="-1.27" y1="1.27" x2="-1.27" y2="-1.27" width="0.127" layer="21"/>
<wire x1="-1.27" y1="-1.27" x2="16.51" y2="-1.27" width="0.127" layer="21"/>
<wire x1="16.51" y1="-1.27" x2="16.51" y2="1.27" width="0.127" layer="21"/>
<wire x1="16.51" y1="1.27" x2="-1.27" y2="1.27" width="0.127" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="330">
<wire x1="-5.08" y1="1.27" x2="5.08" y2="1.27" width="0.254" layer="94"/>
<wire x1="5.08" y1="1.27" x2="5.08" y2="-1.27" width="0.254" layer="94"/>
<wire x1="5.08" y1="-1.27" x2="-5.08" y2="-1.27" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-1.27" x2="-5.08" y2="1.27" width="0.254" layer="94"/>
<wire x1="-3.81" y1="-0.635" x2="-3.81" y2="0.635" width="0.254" layer="94" curve="-180"/>
<wire x1="3.81" y1="0.635" x2="3.81" y2="-0.635" width="0.254" layer="94" curve="-180"/>
<pin name="+" x="-9.525" y="0" length="middle"/>
<pin name="-" x="9.525" y="0" length="middle" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="330">
<gates>
<gate name="G$1" symbol="330" x="0" y="0"/>
</gates>
<devices>
<device name="" package="330">
<connects>
<connect gate="G$1" pin="+" pad="P$1"/>
<connect gate="G$1" pin="-" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U$1" library="Arduino-clone" deviceset="ABK-PRO-MINI" device=""/>
<part name="SERVO-1" library="con-lsta" deviceset="FE05-1" device=""/>
<part name="SERVO-2" library="con-lsta" deviceset="FE05-1" device=""/>
<part name="SERVO-3" library="con-lsta" deviceset="FE05-1" device=""/>
<part name="SERVO-4" library="con-lsta" deviceset="FE05-1" device=""/>
<part name="SERVO-5" library="con-lsta" deviceset="FE05-1" device=""/>
<part name="P+1" library="supply1" deviceset="VCC" device=""/>
<part name="P+2" library="supply1" deviceset="VCC" device=""/>
<part name="P+3" library="supply1" deviceset="VCC" device=""/>
<part name="P+4" library="supply1" deviceset="VCC" device=""/>
<part name="P+5" library="supply1" deviceset="VCC" device=""/>
<part name="P+6" library="supply1" deviceset="VCC" device=""/>
<part name="GND1" library="supply1" deviceset="GND" device=""/>
<part name="GND2" library="supply1" deviceset="GND" device=""/>
<part name="GND3" library="supply1" deviceset="GND" device=""/>
<part name="GND4" library="supply1" deviceset="GND" device=""/>
<part name="GND5" library="supply1" deviceset="GND" device=""/>
<part name="GND6" library="supply1" deviceset="GND" device=""/>
<part name="U$2" library="Power Supply" deviceset="ROWER_SUPPLY" device=""/>
<part name="P+7" library="supply1" deviceset="VCC" device=""/>
<part name="GND7" library="supply1" deviceset="GND" device=""/>
<part name="SV1" library="con-lsta" deviceset="FE06-1" device=""/>
<part name="SV2" library="con-lsta" deviceset="FE07-1" device=""/>
<part name="SV3" library="con-lsta" deviceset="FE08-1" device=""/>
<part name="SV4" library="con-lsta" deviceset="FE05-1" device=""/>
<part name="U$3" library="con-lsta" deviceset="FE02" device=""/>
<part name="U$4" library="2018" deviceset="2018" device=""/>
<part name="U$5" library="2018" deviceset="2018" device=""/>
<part name="U$6" library="330" deviceset="330" device=""/>
<part name="U$7" library="con-lsta" deviceset="FE02" device=""/>
<part name="GND8" library="supply1" deviceset="GND" device=""/>
<part name="P+8" library="supply1" deviceset="VCC" device=""/>
<part name="U$8" library="con-lsta" deviceset="FE02" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="86.36" y="66.04"/>
<instance part="SERVO-1" gate="G$1" x="7.62" y="93.98"/>
<instance part="SERVO-2" gate="G$1" x="7.62" y="76.2"/>
<instance part="SERVO-3" gate="G$1" x="7.62" y="58.42"/>
<instance part="SERVO-4" gate="G$1" x="7.62" y="40.64"/>
<instance part="SERVO-5" gate="G$1" x="7.62" y="22.86"/>
<instance part="P+1" gate="VCC" x="12.7" y="91.44" rot="MR90"/>
<instance part="P+2" gate="VCC" x="12.7" y="73.66" rot="MR90"/>
<instance part="P+3" gate="VCC" x="12.7" y="55.88" rot="MR90"/>
<instance part="P+4" gate="VCC" x="12.7" y="38.1" rot="MR90"/>
<instance part="P+5" gate="VCC" x="12.7" y="20.32" rot="MR90"/>
<instance part="P+6" gate="VCC" x="104.14" y="78.74" rot="MR90"/>
<instance part="GND1" gate="1" x="12.7" y="99.06" rot="R180"/>
<instance part="GND2" gate="1" x="12.7" y="81.28" rot="R180"/>
<instance part="GND3" gate="1" x="12.7" y="63.5" rot="R180"/>
<instance part="GND4" gate="1" x="12.7" y="45.72" rot="R180"/>
<instance part="GND5" gate="1" x="12.7" y="27.94" rot="R180"/>
<instance part="GND6" gate="1" x="109.22" y="81.28" rot="R180"/>
<instance part="U$2" gate="G$1" x="48.895" y="39.37" rot="R270"/>
<instance part="P+7" gate="VCC" x="67.945" y="27.94" rot="MR90"/>
<instance part="GND7" gate="1" x="67.945" y="35.56" rot="R90"/>
<instance part="SV1" gate="G$1" x="81.28" y="101.6" rot="R270"/>
<instance part="SV2" gate="G$1" x="48.895" y="71.12"/>
<instance part="SV3" gate="G$1" x="116.205" y="66.04" rot="R180"/>
<instance part="SV4" gate="G$1" x="81.28" y="38.1" rot="R90"/>
<instance part="U$3" gate="G$1" x="47.625" y="50.8"/>
<instance part="U$4" gate="G$1" x="38.1" y="36.83" rot="R270"/>
<instance part="U$5" gate="G$1" x="38.1" y="29.21" rot="R270"/>
<instance part="U$6" gate="G$1" x="111.76" y="40.005"/>
<instance part="U$7" gate="G$1" x="130.175" y="42.545" rot="R180"/>
<instance part="GND8" gate="1" x="118.11" y="31.75"/>
<instance part="P+8" gate="VCC" x="99.695" y="40.005" rot="MR270"/>
<instance part="U$8" gate="G$1" x="55.88" y="97.155" rot="R270"/>
</instances>
<busses>
</busses>
<nets>
<net name="VCC" class="0">
<segment>
<pinref part="SERVO-1" gate="G$1" pin="VCC"/>
<pinref part="P+1" gate="VCC" pin="VCC"/>
</segment>
<segment>
<pinref part="SERVO-2" gate="G$1" pin="VCC"/>
<pinref part="P+2" gate="VCC" pin="VCC"/>
</segment>
<segment>
<pinref part="SERVO-3" gate="G$1" pin="VCC"/>
<pinref part="P+3" gate="VCC" pin="VCC"/>
</segment>
<segment>
<pinref part="SERVO-4" gate="G$1" pin="VCC"/>
<pinref part="P+4" gate="VCC" pin="VCC"/>
</segment>
<segment>
<pinref part="SERVO-5" gate="G$1" pin="VCC"/>
<pinref part="P+5" gate="VCC" pin="VCC"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="RAW"/>
<pinref part="P+6" gate="VCC" pin="VCC"/>
</segment>
<segment>
<pinref part="U$2" gate="G$1" pin="8"/>
<pinref part="P+7" gate="VCC" pin="VCC"/>
<wire x1="62.23" y1="26.67" x2="62.23" y2="27.94" width="0.1524" layer="91"/>
<wire x1="62.23" y1="27.94" x2="65.405" y2="27.94" width="0.1524" layer="91"/>
<pinref part="U$2" gate="G$1" pin="7"/>
<wire x1="62.23" y1="27.94" x2="62.23" y2="29.21" width="0.1524" layer="91"/>
<junction x="62.23" y="27.94"/>
</segment>
<segment>
<pinref part="U$6" gate="G$1" pin="+"/>
<pinref part="P+8" gate="VCC" pin="VCC"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="GND1" gate="1" pin="GND"/>
<pinref part="SERVO-1" gate="G$1" pin="GND"/>
<wire x1="12.7" y1="96.52" x2="12.7" y2="93.98" width="0.1524" layer="91"/>
<wire x1="12.7" y1="93.98" x2="10.16" y2="93.98" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND2" gate="1" pin="GND"/>
<pinref part="SERVO-2" gate="G$1" pin="GND"/>
<wire x1="12.7" y1="78.74" x2="12.7" y2="76.2" width="0.1524" layer="91"/>
<wire x1="12.7" y1="76.2" x2="10.16" y2="76.2" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND3" gate="1" pin="GND"/>
<pinref part="SERVO-3" gate="G$1" pin="GND"/>
<wire x1="12.7" y1="60.96" x2="12.7" y2="58.42" width="0.1524" layer="91"/>
<wire x1="12.7" y1="58.42" x2="10.16" y2="58.42" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND4" gate="1" pin="GND"/>
<pinref part="SERVO-4" gate="G$1" pin="GND"/>
<wire x1="12.7" y1="43.18" x2="12.7" y2="40.64" width="0.1524" layer="91"/>
<wire x1="12.7" y1="40.64" x2="10.16" y2="40.64" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND5" gate="1" pin="GND"/>
<pinref part="SERVO-5" gate="G$1" pin="GND"/>
<wire x1="12.7" y1="25.4" x2="12.7" y2="22.86" width="0.1524" layer="91"/>
<wire x1="12.7" y1="22.86" x2="10.16" y2="22.86" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="GND"/>
<wire x1="101.6" y1="76.2" x2="109.22" y2="76.2" width="0.1524" layer="91"/>
<pinref part="GND6" gate="1" pin="GND"/>
<wire x1="109.22" y1="76.2" x2="109.22" y2="78.74" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="U$2" gate="G$1" pin="6"/>
<pinref part="GND7" gate="1" pin="GND"/>
<wire x1="62.23" y1="34.29" x2="62.23" y2="35.56" width="0.1524" layer="91"/>
<wire x1="62.23" y1="35.56" x2="65.405" y2="35.56" width="0.1524" layer="91"/>
<pinref part="U$2" gate="G$1" pin="5"/>
<wire x1="62.23" y1="36.83" x2="62.23" y2="35.56" width="0.1524" layer="91"/>
<junction x="62.23" y="35.56"/>
</segment>
<segment>
<pinref part="U$7" gate="G$1" pin="P$2"/>
<pinref part="GND8" gate="1" pin="GND"/>
<wire x1="121.285" y1="37.465" x2="118.11" y2="37.465" width="0.1524" layer="91"/>
<wire x1="118.11" y1="37.465" x2="118.11" y2="34.29" width="0.1524" layer="91"/>
</segment>
</net>
<net name="D5" class="0">
<segment>
<pinref part="SERVO-1" gate="G$1" pin="SIGNAL"/>
<wire x1="10.16" y1="88.9" x2="17.78" y2="88.9" width="0.1524" layer="91"/>
<label x="17.78" y="88.9" size="1.778" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="D5"/>
<wire x1="63.5" y1="60.96" x2="58.42" y2="60.96" width="0.1524" layer="91"/>
<label x="58.42" y="60.96" size="1.016" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="D6" class="0">
<segment>
<pinref part="SERVO-2" gate="G$1" pin="SIGNAL"/>
<wire x1="10.16" y1="71.12" x2="17.78" y2="71.12" width="0.1524" layer="91"/>
<label x="17.78" y="71.12" size="1.778" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="D6"/>
<wire x1="63.5" y1="58.42" x2="58.42" y2="58.42" width="0.1524" layer="91"/>
<label x="58.42" y="58.42" size="1.016" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="D9" class="0">
<segment>
<pinref part="SERVO-3" gate="G$1" pin="SIGNAL"/>
<wire x1="10.16" y1="53.34" x2="17.78" y2="53.34" width="0.1524" layer="91"/>
<label x="17.78" y="53.34" size="1.778" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="D9"/>
<wire x1="63.5" y1="50.8" x2="58.42" y2="50.8" width="0.1524" layer="91"/>
<label x="58.42" y="50.8" size="1.016" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="D10" class="0">
<segment>
<pinref part="SERVO-4" gate="G$1" pin="SIGNAL"/>
<wire x1="10.16" y1="35.56" x2="17.78" y2="35.56" width="0.1524" layer="91"/>
<label x="17.78" y="35.56" size="1.778" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="D10"/>
<wire x1="101.6" y1="50.8" x2="106.68" y2="50.8" width="0.1524" layer="91"/>
<label x="106.68" y="50.8" size="1.016" layer="95" xref="yes"/>
</segment>
</net>
<net name="D11" class="0">
<segment>
<pinref part="SERVO-5" gate="G$1" pin="SIGNAL"/>
<wire x1="10.16" y1="17.78" x2="17.78" y2="17.78" width="0.1524" layer="91"/>
<label x="17.78" y="17.78" size="1.778" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="D11"/>
<wire x1="101.6" y1="53.34" x2="106.68" y2="53.34" width="0.1524" layer="91"/>
<label x="106.68" y="53.34" size="1.016" layer="95" xref="yes"/>
</segment>
</net>
<net name="N$1" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="GND3"/>
<pinref part="SV1" gate="G$1" pin="1"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="GND4"/>
<pinref part="SV1" gate="G$1" pin="2"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="VCC1"/>
<pinref part="SV1" gate="G$1" pin="3"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="RX1-1"/>
<pinref part="SV1" gate="G$1" pin="4"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="TX0-1"/>
<pinref part="SV1" gate="G$1" pin="5"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="DTR"/>
<pinref part="SV1" gate="G$1" pin="6"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="D4"/>
<pinref part="SV2" gate="G$1" pin="1"/>
<wire x1="56.515" y1="63.5" x2="63.5" y2="63.5" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="D3"/>
<pinref part="SV2" gate="G$1" pin="2"/>
<wire x1="56.515" y1="66.04" x2="63.5" y2="66.04" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$9" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="D2"/>
<pinref part="SV2" gate="G$1" pin="3"/>
<wire x1="56.515" y1="68.58" x2="63.5" y2="68.58" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$10" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="GND2"/>
<pinref part="SV2" gate="G$1" pin="4"/>
<wire x1="56.515" y1="71.12" x2="63.5" y2="71.12" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$11" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="RST1"/>
<pinref part="SV2" gate="G$1" pin="5"/>
<wire x1="56.515" y1="73.66" x2="63.5" y2="73.66" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$12" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="RX1"/>
<pinref part="SV2" gate="G$1" pin="6"/>
<wire x1="56.515" y1="76.2" x2="63.5" y2="76.2" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$13" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="TX0"/>
<pinref part="SV2" gate="G$1" pin="7"/>
<wire x1="56.515" y1="78.74" x2="63.5" y2="78.74" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$14" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="A3"/>
<pinref part="SV3" gate="G$1" pin="6"/>
<wire x1="101.6" y1="68.58" x2="108.585" y2="60.96" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$15" class="0">
<segment>
<pinref part="SV3" gate="G$1" pin="3"/>
<pinref part="U$1" gate="G$1" pin="A0"/>
<wire x1="108.585" y1="68.58" x2="101.6" y2="60.96" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$16" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="A2"/>
<pinref part="SV3" gate="G$1" pin="5"/>
<wire x1="101.6" y1="66.04" x2="108.585" y2="63.5" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$17" class="0">
<segment>
<pinref part="SV3" gate="G$1" pin="4"/>
<pinref part="U$1" gate="G$1" pin="A1"/>
<wire x1="108.585" y1="66.04" x2="101.6" y2="63.5" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$18" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="RST"/>
<pinref part="SV3" gate="G$1" pin="1"/>
<wire x1="101.6" y1="73.66" x2="108.585" y2="73.66" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$19" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="VCC"/>
<pinref part="SV3" gate="G$1" pin="2"/>
<wire x1="101.6" y1="71.12" x2="108.585" y2="71.12" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$20" class="0">
<segment>
<pinref part="SV3" gate="G$1" pin="7"/>
<wire x1="108.585" y1="58.42" x2="101.6" y2="58.42" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="D13"/>
</segment>
</net>
<net name="N$21" class="0">
<segment>
<pinref part="SV3" gate="G$1" pin="8"/>
<wire x1="101.6" y1="55.88" x2="108.585" y2="55.88" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="D12"/>
</segment>
</net>
<net name="N$22" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="A7"/>
<pinref part="SV4" gate="G$1" pin="SIGNAL"/>
</segment>
</net>
<net name="N$23" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="A6"/>
<pinref part="SV4" gate="G$1" pin="VCC"/>
</segment>
</net>
<net name="N$24" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="GND1"/>
<pinref part="SV4" gate="G$1" pin="GND"/>
</segment>
</net>
<net name="N$25" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="D8"/>
<pinref part="U$3" gate="G$1" pin="P$1"/>
<wire x1="56.515" y1="53.34" x2="63.5" y2="53.34" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$26" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="D7"/>
<pinref part="U$3" gate="G$1" pin="P$2"/>
<wire x1="56.515" y1="55.88" x2="63.5" y2="55.88" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$27" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="3"/>
<pinref part="U$2" gate="G$1" pin="4"/>
<wire x1="45.085" y1="29.21" x2="45.085" y2="27.94" width="0.1524" layer="91"/>
<pinref part="U$5" gate="G$1" pin="P$1"/>
<wire x1="45.085" y1="27.94" x2="45.085" y2="26.67" width="0.1524" layer="91"/>
<junction x="45.085" y="27.94"/>
</segment>
</net>
<net name="N$30" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="2"/>
<pinref part="U$2" gate="G$1" pin="1"/>
<wire x1="45.085" y1="36.83" x2="45.085" y2="35.56" width="0.1524" layer="91"/>
<pinref part="U$4" gate="G$1" pin="P$1"/>
<wire x1="45.085" y1="35.56" x2="45.085" y2="34.29" width="0.1524" layer="91"/>
<junction x="45.085" y="35.56"/>
</segment>
</net>
<net name="N$28" class="0">
<segment>
<pinref part="U$6" gate="G$1" pin="-"/>
<pinref part="U$7" gate="G$1" pin="P$1"/>
</segment>
</net>
<net name="A5" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="A5"/>
<wire x1="86.36" y1="71.12" x2="85.09" y2="71.12" width="0.1524" layer="91"/>
<label x="85.09" y="71.12" size="1.016" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U$8" gate="G$1" pin="P$1"/>
<wire x1="58.42" y1="88.265" x2="58.42" y2="86.995" width="0.1524" layer="91"/>
<label x="58.42" y="86.995" size="0.8128" layer="95" rot="R270" xref="yes"/>
</segment>
</net>
<net name="A4" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="A4"/>
<wire x1="86.36" y1="66.04" x2="85.09" y2="66.04" width="0.1524" layer="91"/>
<label x="85.09" y="66.04" size="1.016" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U$8" gate="G$1" pin="P$2"/>
<wire x1="60.96" y1="88.265" x2="60.96" y2="86.995" width="0.1524" layer="91"/>
<label x="60.96" y="86.995" size="0.8128" layer="95" rot="R270" xref="yes"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
