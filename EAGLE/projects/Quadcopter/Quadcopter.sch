<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.6.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.05" unitdist="inch" unit="inch" style="lines" multiple="1" display="yes" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="1" fill="3" visible="no" active="no"/>
<layer number="3" name="Route3" color="4" fill="3" visible="no" active="no"/>
<layer number="4" name="Route4" color="1" fill="4" visible="no" active="no"/>
<layer number="5" name="Route5" color="4" fill="4" visible="no" active="no"/>
<layer number="6" name="Route6" color="1" fill="8" visible="no" active="no"/>
<layer number="7" name="Route7" color="4" fill="8" visible="no" active="no"/>
<layer number="8" name="Route8" color="1" fill="2" visible="no" active="no"/>
<layer number="9" name="Route9" color="4" fill="2" visible="no" active="no"/>
<layer number="10" name="Route10" color="1" fill="7" visible="no" active="no"/>
<layer number="11" name="Route11" color="4" fill="7" visible="no" active="no"/>
<layer number="12" name="Route12" color="1" fill="5" visible="no" active="no"/>
<layer number="13" name="Route13" color="4" fill="5" visible="no" active="no"/>
<layer number="14" name="Route14" color="1" fill="6" visible="no" active="no"/>
<layer number="15" name="Route15" color="4" fill="6" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="3" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="15" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="15" fill="1" visible="no" active="no"/>
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
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="101" name="Hidden" color="15" fill="1" visible="yes" active="yes"/>
<layer number="102" name="Changes" color="12" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="diy-modules">
<description>&lt;b&gt;DIY Modules for Arduino, Raspberry Pi, CubieBoard etc.&lt;/b&gt;
&lt;br&gt;&lt;br&gt;
The library contains a list of symbols and footprints for popular, cheap and easy-to-use electronic modules.&lt;br&gt;
The modules are intend to work with microprocessor-based platforms such as &lt;a href="http://arduino.cc"&gt;Arduino&lt;/a&gt;, &lt;a href="http://raspberrypi.org/"&gt;Raspberry Pi&lt;/a&gt;, &lt;a href="http://cubieboard.org/"&gt;CubieBoard&lt;/a&gt;, &lt;a href="http://beagleboard.org/"&gt;BeagleBone&lt;/a&gt; and many others. There are many manufacturers of the modules in the world. Almost all of them can be bought on &lt;a href="ebay.com"&gt;ebay.com&lt;/a&gt;.&lt;br&gt;
&lt;br&gt;
By using this library, you can design a PCB for devices created with usage of modules. Even if you do not need to create PCB design, you can also use the library to quickly document your work by drawing schematics of devices built by you.&lt;br&gt;
&lt;br&gt;
The latest version, examples, photos and much more can be found at: &lt;b&gt;&lt;a href="http://diymodules.org/eagle"&gt;diymodules.org/eagle&lt;/a&gt;&lt;/b&gt;&lt;br&gt;&lt;br&gt;
Comments, suggestions and bug reports please send to: &lt;b&gt;&lt;a href="mailto:eagle@diymodules.org"&gt;eagle@diymodules.org&lt;/b&gt;&lt;/a&gt;&lt;br&gt;&lt;br&gt;
&lt;i&gt;Version: 1.8.0 (2017-Jul-02)&lt;/i&gt;&lt;br&gt;
&lt;i&gt;Created by: Miroslaw Brudnowski&lt;/i&gt;&lt;br&gt;&lt;br&gt;
&lt;i&gt;Released under the Creative Commons Attribution 4.0 International License: &lt;a href="http://creativecommons.org/licenses/by/4.0"&gt;http://creativecommons.org/licenses/by/4.0&lt;/a&gt;&lt;/i&gt;
&lt;br&gt;&lt;br&gt;
&lt;center&gt;
&lt;a href="http://diymodules.org/eagle"&gt;&lt;img src="http://www.diymodules.org/img/diymodules-lbr-image.php?v=1.8.0" alt="DIYmodules.org"&gt;&lt;/a&gt;
&lt;/center&gt;</description>
<packages>
<package name="ARDUINO-PRO-MINI">
<description>&lt;b&gt;Arduino Pro Mini&lt;/b&gt;</description>
<pad name="J6.12" x="15.24" y="7.62" drill="1"/>
<pad name="J6.11" x="12.7" y="7.62" drill="1"/>
<pad name="J6.10" x="10.16" y="7.62" drill="1"/>
<pad name="J6.9" x="7.62" y="7.62" drill="1"/>
<pad name="J6.8" x="5.08" y="7.62" drill="1"/>
<pad name="J6.7" x="2.54" y="7.62" drill="1"/>
<pad name="J6.6" x="0" y="7.62" drill="1"/>
<pad name="J6.5" x="-2.54" y="7.62" drill="1"/>
<pad name="J6.4" x="-5.08" y="7.62" drill="1"/>
<pad name="J6.3" x="-7.62" y="7.62" drill="1"/>
<pad name="J6.2" x="-10.16" y="7.62" drill="1"/>
<pad name="J6.1" x="-12.7" y="7.62" drill="1"/>
<pad name="J3.3" x="15.24" y="5.08" drill="1"/>
<pad name="J3.2" x="15.24" y="2.54" drill="1"/>
<pad name="J3.1" x="15.24" y="0" drill="1"/>
<pad name="J1.1" x="-15.24" y="6.35" drill="1"/>
<pad name="J1.2" x="-15.24" y="3.81" drill="1"/>
<pad name="J1.3" x="-15.24" y="1.27" drill="1"/>
<pad name="J1.4" x="-15.24" y="-1.27" drill="1"/>
<pad name="J1.5" x="-15.24" y="-3.81" drill="1"/>
<pad name="J1.6" x="-15.24" y="-6.35" drill="1"/>
<pad name="J2.2" x="-3.81" y="5.08" drill="1"/>
<pad name="J2.1" x="-1.27" y="5.08" drill="1"/>
<wire x1="16.51" y1="8.255" x2="15.875" y2="8.89" width="0.127" layer="21"/>
<wire x1="14.605" y1="8.89" x2="13.97" y2="8.255" width="0.127" layer="21"/>
<wire x1="12.065" y1="8.89" x2="11.43" y2="8.255" width="0.127" layer="21"/>
<wire x1="11.43" y1="8.255" x2="10.795" y2="8.89" width="0.127" layer="21"/>
<wire x1="8.89" y1="8.255" x2="8.255" y2="8.89" width="0.127" layer="21"/>
<wire x1="6.985" y1="8.89" x2="6.35" y2="8.255" width="0.127" layer="21"/>
<wire x1="6.35" y1="8.255" x2="5.715" y2="8.89" width="0.127" layer="21"/>
<wire x1="4.445" y1="8.89" x2="3.81" y2="8.255" width="0.127" layer="21"/>
<wire x1="3.81" y1="8.255" x2="3.175" y2="8.89" width="0.127" layer="21"/>
<wire x1="1.905" y1="8.89" x2="1.27" y2="8.255" width="0.127" layer="21"/>
<wire x1="1.27" y1="8.255" x2="0.635" y2="8.89" width="0.127" layer="21"/>
<wire x1="-0.635" y1="8.89" x2="-1.27" y2="8.255" width="0.127" layer="21"/>
<wire x1="-1.27" y1="8.255" x2="-1.905" y2="8.89" width="0.127" layer="21"/>
<wire x1="-3.175" y1="8.89" x2="-3.81" y2="8.255" width="0.127" layer="21"/>
<wire x1="-3.81" y1="8.255" x2="-4.445" y2="8.89" width="0.127" layer="21"/>
<wire x1="-5.715" y1="8.89" x2="-6.35" y2="8.255" width="0.127" layer="21"/>
<wire x1="-8.255" y1="8.89" x2="-8.89" y2="8.255" width="0.127" layer="21"/>
<wire x1="-8.89" y1="8.255" x2="-9.525" y2="8.89" width="0.127" layer="21"/>
<wire x1="-10.795" y1="8.89" x2="-11.43" y2="8.255" width="0.127" layer="21"/>
<wire x1="-11.43" y1="8.255" x2="-12.065" y2="8.89" width="0.127" layer="21"/>
<wire x1="-13.335" y1="8.89" x2="-13.97" y2="8.255" width="0.127" layer="21"/>
<wire x1="-13.97" y1="8.255" x2="-13.97" y2="6.985" width="0.127" layer="21"/>
<wire x1="-13.97" y1="6.985" x2="-13.335" y2="6.35" width="0.127" layer="21"/>
<wire x1="-13.335" y1="6.35" x2="-12.065" y2="6.35" width="0.127" layer="21"/>
<wire x1="-12.065" y1="6.35" x2="-11.43" y2="6.985" width="0.127" layer="21"/>
<wire x1="-11.43" y1="6.985" x2="-10.795" y2="6.35" width="0.127" layer="21"/>
<wire x1="-10.795" y1="6.35" x2="-9.525" y2="6.35" width="0.127" layer="21"/>
<wire x1="-9.525" y1="6.35" x2="-8.89" y2="6.985" width="0.127" layer="21"/>
<wire x1="-8.89" y1="6.985" x2="-8.255" y2="6.35" width="0.127" layer="21"/>
<wire x1="-8.255" y1="6.35" x2="-6.985" y2="6.35" width="0.127" layer="21"/>
<wire x1="-6.985" y1="6.35" x2="-6.35" y2="6.985" width="0.127" layer="21"/>
<wire x1="-6.35" y1="6.985" x2="-5.715" y2="6.35" width="0.127" layer="21"/>
<wire x1="-5.715" y1="6.35" x2="-4.445" y2="6.35" width="0.127" layer="21"/>
<wire x1="-4.445" y1="6.35" x2="-3.81" y2="6.985" width="0.127" layer="21"/>
<wire x1="-3.81" y1="6.985" x2="-3.175" y2="6.35" width="0.127" layer="21"/>
<wire x1="-3.175" y1="6.35" x2="-1.905" y2="6.35" width="0.127" layer="21"/>
<wire x1="-1.905" y1="6.35" x2="-1.27" y2="6.985" width="0.127" layer="21"/>
<wire x1="-1.27" y1="6.985" x2="-0.635" y2="6.35" width="0.127" layer="21"/>
<wire x1="-0.635" y1="6.35" x2="0.635" y2="6.35" width="0.127" layer="21"/>
<wire x1="0.635" y1="6.35" x2="1.27" y2="6.985" width="0.127" layer="21"/>
<wire x1="1.27" y1="6.985" x2="1.905" y2="6.35" width="0.127" layer="21"/>
<wire x1="1.905" y1="6.35" x2="3.175" y2="6.35" width="0.127" layer="21"/>
<wire x1="3.175" y1="6.35" x2="3.81" y2="6.985" width="0.127" layer="21"/>
<wire x1="3.81" y1="6.985" x2="4.445" y2="6.35" width="0.127" layer="21"/>
<wire x1="4.445" y1="6.35" x2="5.715" y2="6.35" width="0.127" layer="21"/>
<wire x1="5.715" y1="6.35" x2="6.35" y2="6.985" width="0.127" layer="21"/>
<wire x1="6.35" y1="6.985" x2="6.985" y2="6.35" width="0.127" layer="21"/>
<wire x1="6.985" y1="6.35" x2="8.255" y2="6.35" width="0.127" layer="21"/>
<wire x1="8.255" y1="6.35" x2="8.89" y2="6.985" width="0.127" layer="21"/>
<wire x1="8.89" y1="6.985" x2="9.525" y2="6.35" width="0.127" layer="21"/>
<wire x1="9.525" y1="6.35" x2="10.795" y2="6.35" width="0.127" layer="21"/>
<wire x1="10.795" y1="6.35" x2="11.43" y2="6.985" width="0.127" layer="21"/>
<wire x1="11.43" y1="6.985" x2="12.065" y2="6.35" width="0.127" layer="21"/>
<wire x1="12.065" y1="6.35" x2="13.335" y2="6.35" width="0.127" layer="21"/>
<wire x1="13.335" y1="6.35" x2="13.97" y2="6.985" width="0.127" layer="21"/>
<wire x1="13.97" y1="6.985" x2="14.605" y2="6.35" width="0.127" layer="21"/>
<wire x1="14.605" y1="6.35" x2="15.875" y2="6.35" width="0.127" layer="21"/>
<wire x1="15.875" y1="6.35" x2="16.51" y2="6.985" width="0.127" layer="21"/>
<pad name="J7.1" x="15.24" y="-7.62" drill="1"/>
<pad name="J7.2" x="12.7" y="-7.62" drill="1"/>
<pad name="J7.3" x="10.16" y="-7.62" drill="1"/>
<pad name="J7.4" x="7.62" y="-7.62" drill="1"/>
<pad name="J7.5" x="5.08" y="-7.62" drill="1"/>
<pad name="J7.6" x="2.54" y="-7.62" drill="1"/>
<pad name="J7.8" x="-2.54" y="-7.62" drill="1"/>
<pad name="J7.9" x="-5.08" y="-7.62" drill="1"/>
<pad name="J7.11" x="-10.16" y="-7.62" drill="1"/>
<pad name="J7.12" x="-12.7" y="-7.62" drill="1"/>
<wire x1="16.51" y1="-6.985" x2="15.875" y2="-6.35" width="0.127" layer="21"/>
<wire x1="-13.335" y1="-6.35" x2="-13.97" y2="-6.985" width="0.127" layer="21"/>
<wire x1="-13.97" y1="-6.985" x2="-13.97" y2="-8.255" width="0.127" layer="21"/>
<wire x1="15.875" y1="-8.89" x2="16.51" y2="-8.255" width="0.127" layer="21"/>
<wire x1="-14.605" y1="7.62" x2="-15.875" y2="7.62" width="0.127" layer="21"/>
<wire x1="-15.875" y1="7.62" x2="-16.51" y2="6.985" width="0.127" layer="21"/>
<wire x1="-16.51" y1="5.715" x2="-15.875" y2="5.08" width="0.127" layer="21"/>
<wire x1="-15.875" y1="5.08" x2="-16.51" y2="4.445" width="0.127" layer="21"/>
<wire x1="-16.51" y1="3.175" x2="-15.875" y2="2.54" width="0.127" layer="21"/>
<wire x1="-15.875" y1="2.54" x2="-16.51" y2="1.905" width="0.127" layer="21"/>
<wire x1="-16.51" y1="0.635" x2="-15.875" y2="0" width="0.127" layer="21"/>
<wire x1="-15.875" y1="0" x2="-16.51" y2="-0.635" width="0.127" layer="21"/>
<wire x1="-16.51" y1="-1.905" x2="-15.875" y2="-2.54" width="0.127" layer="21"/>
<wire x1="-15.875" y1="-2.54" x2="-16.51" y2="-3.175" width="0.127" layer="21"/>
<wire x1="-16.51" y1="-4.445" x2="-15.875" y2="-5.08" width="0.127" layer="21"/>
<wire x1="-15.875" y1="-5.08" x2="-16.51" y2="-5.715" width="0.127" layer="21"/>
<wire x1="-16.51" y1="-6.985" x2="-15.875" y2="-7.62" width="0.127" layer="21"/>
<wire x1="-15.875" y1="-7.62" x2="-14.605" y2="-7.62" width="0.127" layer="21"/>
<wire x1="-14.605" y1="-7.62" x2="-13.97" y2="-6.985" width="0.127" layer="21"/>
<wire x1="-13.97" y1="-6.985" x2="-13.97" y2="-5.715" width="0.127" layer="21"/>
<wire x1="-13.97" y1="-5.715" x2="-14.605" y2="-5.08" width="0.127" layer="21"/>
<wire x1="-14.605" y1="-5.08" x2="-13.97" y2="-4.445" width="0.127" layer="21"/>
<wire x1="-13.97" y1="-4.445" x2="-13.97" y2="-3.175" width="0.127" layer="21"/>
<wire x1="-13.97" y1="-3.175" x2="-14.605" y2="-2.54" width="0.127" layer="21"/>
<wire x1="-14.605" y1="-2.54" x2="-13.97" y2="-1.905" width="0.127" layer="21"/>
<wire x1="-13.97" y1="-1.905" x2="-13.97" y2="-0.635" width="0.127" layer="21"/>
<wire x1="-13.97" y1="-0.635" x2="-14.605" y2="0" width="0.127" layer="21"/>
<wire x1="-14.605" y1="0" x2="-13.97" y2="0.635" width="0.127" layer="21"/>
<wire x1="-13.97" y1="0.635" x2="-13.97" y2="1.905" width="0.127" layer="21"/>
<wire x1="-13.97" y1="1.905" x2="-14.605" y2="2.54" width="0.127" layer="21"/>
<wire x1="-14.605" y1="2.54" x2="-13.97" y2="3.175" width="0.127" layer="21"/>
<wire x1="-13.97" y1="3.175" x2="-13.97" y2="4.445" width="0.127" layer="21"/>
<wire x1="-13.97" y1="4.445" x2="-14.605" y2="5.08" width="0.127" layer="21"/>
<wire x1="-14.605" y1="5.08" x2="-13.97" y2="5.715" width="0.127" layer="21"/>
<wire x1="-13.97" y1="5.715" x2="-13.97" y2="6.985" width="0.127" layer="21"/>
<wire x1="-13.97" y1="6.985" x2="-14.605" y2="7.62" width="0.127" layer="21"/>
<wire x1="-5.08" y1="5.715" x2="-4.445" y2="6.35" width="0.127" layer="21"/>
<wire x1="-4.445" y1="6.35" x2="-3.175" y2="6.35" width="0.127" layer="21"/>
<wire x1="-3.175" y1="6.35" x2="-2.54" y2="5.715" width="0.127" layer="21"/>
<wire x1="-2.54" y1="5.715" x2="-1.905" y2="6.35" width="0.127" layer="21"/>
<wire x1="-1.905" y1="6.35" x2="-0.635" y2="6.35" width="0.127" layer="21"/>
<wire x1="-0.635" y1="6.35" x2="0" y2="5.715" width="0.127" layer="21"/>
<wire x1="0" y1="5.715" x2="0" y2="4.445" width="0.127" layer="21"/>
<wire x1="0" y1="4.445" x2="-0.635" y2="3.81" width="0.127" layer="21"/>
<wire x1="-0.635" y1="3.81" x2="-1.905" y2="3.81" width="0.127" layer="21"/>
<wire x1="-1.905" y1="3.81" x2="-2.54" y2="4.445" width="0.127" layer="21"/>
<wire x1="-2.54" y1="4.445" x2="-3.175" y2="3.81" width="0.127" layer="21"/>
<wire x1="-3.175" y1="3.81" x2="-4.445" y2="3.81" width="0.127" layer="21"/>
<wire x1="-4.445" y1="3.81" x2="-5.08" y2="4.445" width="0.127" layer="21"/>
<wire x1="-5.08" y1="4.445" x2="-5.08" y2="5.715" width="0.127" layer="21"/>
<wire x1="15.875" y1="6.35" x2="16.51" y2="5.715" width="0.127" layer="21"/>
<wire x1="16.51" y1="4.445" x2="15.875" y2="3.81" width="0.127" layer="21"/>
<wire x1="15.875" y1="3.81" x2="16.51" y2="3.175" width="0.127" layer="21"/>
<wire x1="16.51" y1="1.905" x2="15.875" y2="1.27" width="0.127" layer="21"/>
<wire x1="15.875" y1="1.27" x2="16.51" y2="0.635" width="0.127" layer="21"/>
<wire x1="16.51" y1="-0.635" x2="15.875" y2="-1.27" width="0.127" layer="21"/>
<wire x1="15.875" y1="-1.27" x2="14.605" y2="-1.27" width="0.127" layer="21"/>
<wire x1="14.605" y1="-1.27" x2="13.97" y2="-0.635" width="0.127" layer="21"/>
<wire x1="13.97" y1="-0.635" x2="13.97" y2="0.635" width="0.127" layer="21"/>
<wire x1="13.97" y1="0.635" x2="14.605" y2="1.27" width="0.127" layer="21"/>
<wire x1="14.605" y1="1.27" x2="13.97" y2="1.905" width="0.127" layer="21"/>
<wire x1="13.97" y1="1.905" x2="13.97" y2="3.175" width="0.127" layer="21"/>
<wire x1="13.97" y1="3.175" x2="14.605" y2="3.81" width="0.127" layer="21"/>
<wire x1="14.605" y1="3.81" x2="13.97" y2="4.445" width="0.127" layer="21"/>
<wire x1="13.97" y1="4.445" x2="13.97" y2="5.715" width="0.127" layer="21"/>
<wire x1="13.97" y1="5.715" x2="14.605" y2="6.35" width="0.127" layer="21"/>
<wire x1="-13.335" y1="-8.89" x2="-13.97" y2="-8.255" width="0.127" layer="21"/>
<pad name="J7.10" x="-7.62" y="-7.62" drill="1"/>
<pad name="J7.7" x="0" y="-7.62" drill="1"/>
<wire x1="16.51" y1="8.89" x2="13.335" y2="8.89" width="0.127" layer="21"/>
<wire x1="13.335" y1="8.89" x2="9.525" y2="8.89" width="0.127" layer="21"/>
<wire x1="9.525" y1="8.89" x2="-6.985" y2="8.89" width="0.127" layer="21"/>
<wire x1="-6.985" y1="8.89" x2="-16.51" y2="8.89" width="0.127" layer="21"/>
<wire x1="-16.51" y1="-8.89" x2="-12.065" y2="-8.89" width="0.127" layer="21"/>
<wire x1="-12.065" y1="-8.89" x2="-10.795" y2="-8.89" width="0.127" layer="21"/>
<wire x1="-10.795" y1="-8.89" x2="-9.525" y2="-8.89" width="0.127" layer="21"/>
<wire x1="-9.525" y1="-8.89" x2="-8.255" y2="-8.89" width="0.127" layer="21"/>
<wire x1="-8.255" y1="-8.89" x2="-6.985" y2="-8.89" width="0.127" layer="21"/>
<wire x1="-6.985" y1="-8.89" x2="-5.715" y2="-8.89" width="0.127" layer="21"/>
<wire x1="-5.715" y1="-8.89" x2="-4.445" y2="-8.89" width="0.127" layer="21"/>
<wire x1="-4.445" y1="-8.89" x2="-3.175" y2="-8.89" width="0.127" layer="21"/>
<wire x1="-3.175" y1="-8.89" x2="-1.905" y2="-8.89" width="0.127" layer="21"/>
<wire x1="-1.905" y1="-8.89" x2="-0.635" y2="-8.89" width="0.127" layer="21"/>
<wire x1="-0.635" y1="-8.89" x2="0.635" y2="-8.89" width="0.127" layer="21"/>
<wire x1="0.635" y1="-8.89" x2="1.905" y2="-8.89" width="0.127" layer="21"/>
<wire x1="1.905" y1="-8.89" x2="3.175" y2="-8.89" width="0.127" layer="21"/>
<wire x1="3.175" y1="-8.89" x2="4.445" y2="-8.89" width="0.127" layer="21"/>
<wire x1="4.445" y1="-8.89" x2="5.715" y2="-8.89" width="0.127" layer="21"/>
<wire x1="5.715" y1="-8.89" x2="6.985" y2="-8.89" width="0.127" layer="21"/>
<wire x1="6.985" y1="-8.89" x2="8.255" y2="-8.89" width="0.127" layer="21"/>
<wire x1="8.255" y1="-8.89" x2="9.525" y2="-8.89" width="0.127" layer="21"/>
<wire x1="9.525" y1="-8.89" x2="10.795" y2="-8.89" width="0.127" layer="21"/>
<wire x1="10.795" y1="-8.89" x2="12.065" y2="-8.89" width="0.127" layer="21"/>
<wire x1="12.065" y1="-8.89" x2="13.335" y2="-8.89" width="0.127" layer="21"/>
<wire x1="13.335" y1="-8.89" x2="14.605" y2="-8.89" width="0.127" layer="21"/>
<wire x1="14.605" y1="-8.89" x2="16.51" y2="-8.89" width="0.127" layer="21"/>
<wire x1="-16.51" y1="8.89" x2="-16.51" y2="-8.89" width="0.127" layer="21"/>
<wire x1="16.51" y1="-8.89" x2="16.51" y2="8.89" width="0.127" layer="21"/>
<wire x1="-6.35" y1="8.255" x2="-6.985" y2="8.89" width="0.127" layer="21"/>
<wire x1="13.97" y1="8.255" x2="13.335" y2="8.89" width="0.127" layer="21"/>
<wire x1="8.89" y1="8.255" x2="9.525" y2="8.89" width="0.127" layer="21"/>
<wire x1="-12.065" y1="-8.89" x2="-11.43" y2="-8.255" width="0.127" layer="21"/>
<wire x1="-11.43" y1="-8.255" x2="-10.795" y2="-8.89" width="0.127" layer="21"/>
<wire x1="-9.525" y1="-8.89" x2="-8.89" y2="-8.255" width="0.127" layer="21"/>
<wire x1="-8.89" y1="-8.255" x2="-8.255" y2="-8.89" width="0.127" layer="21"/>
<wire x1="-6.985" y1="-8.89" x2="-6.35" y2="-8.255" width="0.127" layer="21"/>
<wire x1="-6.35" y1="-8.255" x2="-5.715" y2="-8.89" width="0.127" layer="21"/>
<wire x1="-4.445" y1="-8.89" x2="-3.81" y2="-8.255" width="0.127" layer="21"/>
<wire x1="-3.81" y1="-8.255" x2="-3.175" y2="-8.89" width="0.127" layer="21"/>
<wire x1="-1.905" y1="-8.89" x2="-1.27" y2="-8.255" width="0.127" layer="21"/>
<wire x1="-1.27" y1="-8.255" x2="-0.635" y2="-8.89" width="0.127" layer="21"/>
<wire x1="0.635" y1="-8.89" x2="1.27" y2="-8.255" width="0.127" layer="21"/>
<wire x1="1.27" y1="-8.255" x2="1.905" y2="-8.89" width="0.127" layer="21"/>
<wire x1="3.175" y1="-8.89" x2="3.81" y2="-8.255" width="0.127" layer="21"/>
<wire x1="3.81" y1="-8.255" x2="4.445" y2="-8.89" width="0.127" layer="21"/>
<wire x1="5.715" y1="-8.89" x2="6.35" y2="-8.255" width="0.127" layer="21"/>
<wire x1="6.35" y1="-8.255" x2="6.985" y2="-8.89" width="0.127" layer="21"/>
<wire x1="8.255" y1="-8.89" x2="8.89" y2="-8.255" width="0.127" layer="21"/>
<wire x1="8.89" y1="-8.255" x2="9.525" y2="-8.89" width="0.127" layer="21"/>
<wire x1="10.795" y1="-8.89" x2="11.43" y2="-8.255" width="0.127" layer="21"/>
<wire x1="11.43" y1="-8.255" x2="12.065" y2="-8.89" width="0.127" layer="21"/>
<wire x1="-13.335" y1="-6.35" x2="-12.065" y2="-6.35" width="0.127" layer="21"/>
<wire x1="-12.065" y1="-6.35" x2="-11.43" y2="-6.985" width="0.127" layer="21"/>
<wire x1="-11.43" y1="-6.985" x2="-10.795" y2="-6.35" width="0.127" layer="21"/>
<wire x1="-10.795" y1="-6.35" x2="-9.525" y2="-6.35" width="0.127" layer="21"/>
<wire x1="-9.525" y1="-6.35" x2="-8.89" y2="-6.985" width="0.127" layer="21"/>
<wire x1="-8.89" y1="-6.985" x2="-8.255" y2="-6.35" width="0.127" layer="21"/>
<wire x1="-8.255" y1="-6.35" x2="-6.985" y2="-6.35" width="0.127" layer="21"/>
<wire x1="-6.985" y1="-6.35" x2="-6.35" y2="-6.985" width="0.127" layer="21"/>
<wire x1="-6.35" y1="-6.985" x2="-5.715" y2="-6.35" width="0.127" layer="21"/>
<wire x1="-5.715" y1="-6.35" x2="-4.445" y2="-6.35" width="0.127" layer="21"/>
<wire x1="-4.445" y1="-6.35" x2="-3.81" y2="-6.985" width="0.127" layer="21"/>
<wire x1="-3.81" y1="-6.985" x2="-3.175" y2="-6.35" width="0.127" layer="21"/>
<wire x1="-3.175" y1="-6.35" x2="-1.905" y2="-6.35" width="0.127" layer="21"/>
<wire x1="-1.905" y1="-6.35" x2="-1.27" y2="-6.985" width="0.127" layer="21"/>
<wire x1="-1.27" y1="-6.985" x2="-0.635" y2="-6.35" width="0.127" layer="21"/>
<wire x1="-0.635" y1="-6.35" x2="0.635" y2="-6.35" width="0.127" layer="21"/>
<wire x1="0.635" y1="-6.35" x2="1.27" y2="-6.985" width="0.127" layer="21"/>
<wire x1="1.27" y1="-6.985" x2="1.905" y2="-6.35" width="0.127" layer="21"/>
<wire x1="1.905" y1="-6.35" x2="3.175" y2="-6.35" width="0.127" layer="21"/>
<wire x1="3.175" y1="-6.35" x2="3.81" y2="-6.985" width="0.127" layer="21"/>
<wire x1="3.81" y1="-6.985" x2="4.445" y2="-6.35" width="0.127" layer="21"/>
<wire x1="4.445" y1="-6.35" x2="5.715" y2="-6.35" width="0.127" layer="21"/>
<wire x1="5.715" y1="-6.35" x2="6.35" y2="-6.985" width="0.127" layer="21"/>
<wire x1="6.35" y1="-6.985" x2="6.985" y2="-6.35" width="0.127" layer="21"/>
<wire x1="6.985" y1="-6.35" x2="8.255" y2="-6.35" width="0.127" layer="21"/>
<wire x1="8.255" y1="-6.35" x2="8.89" y2="-6.985" width="0.127" layer="21"/>
<wire x1="8.89" y1="-6.985" x2="9.525" y2="-6.35" width="0.127" layer="21"/>
<wire x1="9.525" y1="-6.35" x2="10.795" y2="-6.35" width="0.127" layer="21"/>
<wire x1="10.795" y1="-6.35" x2="11.43" y2="-6.985" width="0.127" layer="21"/>
<wire x1="11.43" y1="-6.985" x2="12.065" y2="-6.35" width="0.127" layer="21"/>
<wire x1="12.065" y1="-6.35" x2="13.335" y2="-6.35" width="0.127" layer="21"/>
<wire x1="13.335" y1="-6.35" x2="13.97" y2="-6.985" width="0.127" layer="21"/>
<wire x1="13.97" y1="-6.985" x2="14.605" y2="-6.35" width="0.127" layer="21"/>
<wire x1="14.605" y1="-6.35" x2="15.875" y2="-6.35" width="0.127" layer="21"/>
<wire x1="14.605" y1="-8.89" x2="13.97" y2="-8.255" width="0.127" layer="21"/>
<wire x1="13.97" y1="-8.255" x2="13.335" y2="-8.89" width="0.127" layer="21"/>
<text x="0" y="10.16" size="1.27" layer="25" align="bottom-center">&gt;NAME</text>
<text x="0" y="-10.16" size="1.27" layer="27" align="top-center">&gt;VALUE</text>
</package>
</packages>
<symbols>
<symbol name="ARDUINO-PRO-MINI">
<description>&lt;b&gt;Arduino Pro Mini&lt;/b&gt;</description>
<pin name="D1/TX" x="-17.78" y="12.7" length="middle"/>
<pin name="D0/RX" x="-17.78" y="10.16" length="middle"/>
<pin name="RST.1" x="-17.78" y="7.62" length="middle"/>
<pin name="GND.1" x="-17.78" y="5.08" length="middle" direction="pwr"/>
<pin name="D2" x="-17.78" y="2.54" length="middle"/>
<pin name="D3" x="-17.78" y="0" length="middle"/>
<pin name="D4" x="-17.78" y="-2.54" length="middle"/>
<pin name="D5" x="-17.78" y="-5.08" length="middle"/>
<pin name="D6" x="-17.78" y="-7.62" length="middle"/>
<pin name="D7" x="-17.78" y="-10.16" length="middle"/>
<pin name="D8" x="-17.78" y="-12.7" length="middle"/>
<pin name="D9" x="-17.78" y="-15.24" length="middle"/>
<pin name="RAW" x="17.78" y="12.7" length="middle" direction="pwr" rot="R180"/>
<pin name="GND.2" x="17.78" y="10.16" length="middle" direction="pwr" rot="R180"/>
<pin name="RST.2" x="17.78" y="7.62" length="middle" rot="R180"/>
<pin name="VCC" x="17.78" y="5.08" length="middle" direction="pwr" rot="R180"/>
<pin name="A3" x="17.78" y="2.54" length="middle" rot="R180"/>
<pin name="A2" x="17.78" y="0" length="middle" rot="R180"/>
<pin name="A1" x="17.78" y="-2.54" length="middle" rot="R180"/>
<pin name="A0" x="17.78" y="-5.08" length="middle" rot="R180"/>
<pin name="D13" x="17.78" y="-7.62" length="middle" rot="R180"/>
<pin name="D12" x="17.78" y="-10.16" length="middle" rot="R180"/>
<pin name="D11" x="17.78" y="-12.7" length="middle" rot="R180"/>
<pin name="D10" x="17.78" y="-15.24" length="middle" rot="R180"/>
<pin name="P_GND" x="5.08" y="35.56" length="middle" rot="R270"/>
<pin name="P_CTS" x="2.54" y="35.56" length="middle" rot="R270"/>
<pin name="P_VCC" x="0" y="35.56" length="middle" rot="R270"/>
<pin name="P_RXD" x="-2.54" y="35.56" length="middle" rot="R270"/>
<pin name="P_TXD" x="-5.08" y="35.56" length="middle" rot="R270"/>
<pin name="P_DTR" x="-7.62" y="35.56" length="middle" rot="R270"/>
<wire x1="-12.7" y1="30.48" x2="12.7" y2="30.48" width="0.254" layer="94"/>
<wire x1="12.7" y1="30.48" x2="12.7" y2="-30.48" width="0.254" layer="94"/>
<wire x1="12.7" y1="-30.48" x2="-12.7" y2="-30.48" width="0.254" layer="94"/>
<wire x1="-12.7" y1="-30.48" x2="-12.7" y2="30.48" width="0.254" layer="94"/>
<text x="15.24" y="27.94" size="1.778" layer="95">&gt;NAME</text>
<text x="15.24" y="25.4" size="1.778" layer="96">&gt;VALUE</text>
<pin name="A7" x="17.78" y="-20.32" length="middle" rot="R180"/>
<pin name="A6" x="17.78" y="-22.86" length="middle" rot="R180"/>
<pin name="GND.3" x="17.78" y="-25.4" length="middle" rot="R180"/>
<pin name="A4" x="17.78" y="17.78" length="middle" rot="R180"/>
<pin name="A5" x="17.78" y="20.32" length="middle" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="ARDUINO-PRO-MINI-*" prefix="M">
<description>&lt;b&gt;Arduino Pro Mini&lt;/b&gt; and compatible devices
&lt;p&gt;More details available here:&lt;br&gt;
&lt;a href="https://www.arduino.cc/en/Main/ArduinoBoardProMini"&gt;https://www.arduino.cc/en/Main/ArduinoBoardProMini&lt;/a&gt;&lt;/p&gt;
&lt;p&gt;&lt;b&gt;&lt;a href="http://www.ebay.com/sch/arduino+pro+mini"&gt;Click here to find device on ebay.com&lt;/a&gt;&lt;/b&gt;&lt;/p&gt;

&lt;p&gt;&lt;img alt="photo" src="http://www.diymodules.org/img/device-photo.php?name=ARDUINO-PRO-MINI-"&gt;&lt;/p&gt;</description>
<gates>
<gate name="G$1" symbol="ARDUINO-PRO-MINI" x="0" y="0"/>
</gates>
<devices>
<device name="" package="ARDUINO-PRO-MINI">
<connects>
<connect gate="G$1" pin="A0" pad="J6.8"/>
<connect gate="G$1" pin="A1" pad="J6.7"/>
<connect gate="G$1" pin="A2" pad="J6.6"/>
<connect gate="G$1" pin="A3" pad="J6.5"/>
<connect gate="G$1" pin="A4" pad="J2.1"/>
<connect gate="G$1" pin="A5" pad="J2.2"/>
<connect gate="G$1" pin="A6" pad="J3.2"/>
<connect gate="G$1" pin="A7" pad="J3.3"/>
<connect gate="G$1" pin="D0/RX" pad="J7.11"/>
<connect gate="G$1" pin="D1/TX" pad="J7.12"/>
<connect gate="G$1" pin="D10" pad="J6.12"/>
<connect gate="G$1" pin="D11" pad="J6.11"/>
<connect gate="G$1" pin="D12" pad="J6.10"/>
<connect gate="G$1" pin="D13" pad="J6.9"/>
<connect gate="G$1" pin="D2" pad="J7.8"/>
<connect gate="G$1" pin="D3" pad="J7.7"/>
<connect gate="G$1" pin="D4" pad="J7.6"/>
<connect gate="G$1" pin="D5" pad="J7.5"/>
<connect gate="G$1" pin="D6" pad="J7.4"/>
<connect gate="G$1" pin="D7" pad="J7.3"/>
<connect gate="G$1" pin="D8" pad="J7.2"/>
<connect gate="G$1" pin="D9" pad="J7.1"/>
<connect gate="G$1" pin="GND.1" pad="J7.9"/>
<connect gate="G$1" pin="GND.2" pad="J6.2"/>
<connect gate="G$1" pin="GND.3" pad="J3.1"/>
<connect gate="G$1" pin="P_CTS" pad="J1.2"/>
<connect gate="G$1" pin="P_DTR" pad="J1.6"/>
<connect gate="G$1" pin="P_GND" pad="J1.1"/>
<connect gate="G$1" pin="P_RXD" pad="J1.4"/>
<connect gate="G$1" pin="P_TXD" pad="J1.5"/>
<connect gate="G$1" pin="P_VCC" pad="J1.3"/>
<connect gate="G$1" pin="RAW" pad="J6.1"/>
<connect gate="G$1" pin="RST.1" pad="J7.10"/>
<connect gate="G$1" pin="RST.2" pad="J6.3"/>
<connect gate="G$1" pin="VCC" pad="J6.4"/>
</connects>
<technologies>
<technology name="3.3V"/>
<technology name="5.0V"/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="gy-521">
<packages>
<package name="GY-521">
<pad name="SDA" x="-10.4775" y="1.27" drill="0.8" diameter="1.778"/>
<pad name="XDA" x="-10.4775" y="-1.27" drill="0.8" diameter="1.778"/>
<pad name="SCL" x="-10.4775" y="3.81" drill="0.8" diameter="1.778"/>
<pad name="GND" x="-10.4775" y="6.35" drill="0.8" diameter="1.778"/>
<pad name="VCC" x="-10.4775" y="8.89" drill="0.8" diameter="1.778"/>
<pad name="XCL" x="-10.4775" y="-3.81" drill="0.8" diameter="1.778"/>
<pad name="ADO" x="-10.4775" y="-6.35" drill="0.8" diameter="1.778"/>
<pad name="INT" x="-10.4775" y="-8.89" drill="0.8" diameter="1.778"/>
<wire x1="-11.43" y1="10.00125" x2="4.445" y2="10.00125" width="0.127" layer="21"/>
<wire x1="4.445" y1="10.00125" x2="4.445" y2="-10.16" width="0.127" layer="21"/>
<wire x1="4.445" y1="-10.16" x2="-11.43" y2="-10.16" width="0.127" layer="21"/>
<wire x1="-11.43" y1="-10.16" x2="-11.43" y2="10.00125" width="0.127" layer="21"/>
<wire x1="-2.54" y1="-8.89" x2="1.27" y2="-8.89" width="0.127" layer="21"/>
<wire x1="1.27" y1="-8.89" x2="0.635" y2="-8.255" width="0.127" layer="21"/>
<wire x1="1.27" y1="-8.89" x2="0.635" y2="-9.525" width="0.127" layer="21"/>
<wire x1="-2.54" y1="-8.89" x2="-2.54" y2="-5.08" width="0.127" layer="21"/>
<wire x1="-2.54" y1="-5.08" x2="-1.905" y2="-5.715" width="0.127" layer="21"/>
<wire x1="-2.54" y1="-5.08" x2="-3.175" y2="-5.715" width="0.127" layer="21"/>
<text x="1.905" y="-8.89" size="1.27" layer="21">x</text>
<text x="-1.27" y="-5.08" size="1.27" layer="21">y</text>
<text x="3.81" y="-1.27" size="1.27" layer="21" rot="R90">ITG/MPU</text>
</package>
</packages>
<symbols>
<symbol name="MPU6050">
<wire x1="-10.16" y1="17.78" x2="-10.16" y2="-22.86" width="0.6096" layer="94"/>
<wire x1="-10.16" y1="-22.86" x2="17.78" y2="-22.86" width="0.6096" layer="94"/>
<wire x1="17.78" y1="-22.86" x2="17.78" y2="17.78" width="0.6096" layer="94"/>
<wire x1="17.78" y1="17.78" x2="-10.16" y2="17.78" width="0.6096" layer="94"/>
<text x="13.716" y="-9.398" size="1.778" layer="94" rot="R270">GY-521</text>
<text x="15.24" y="-7.62" size="1.778" layer="94" rot="R90">ITG/MPU</text>
<pin name="VCC" x="-15.24" y="15.24" length="middle"/>
<pin name="GND" x="-15.24" y="10.16" length="middle"/>
<pin name="SCL" x="-15.24" y="5.08" length="middle"/>
<pin name="SDA" x="-15.24" y="0" length="middle"/>
<pin name="XDA" x="-15.24" y="-5.08" length="middle"/>
<pin name="XCL" x="-15.24" y="-10.16" length="middle"/>
<pin name="ADO" x="-15.24" y="-15.24" length="middle"/>
<pin name="INT" x="-15.24" y="-20.32" length="middle"/>
<wire x1="2.54" y1="-20.32" x2="7.62" y2="-20.32" width="0.3048" layer="94"/>
<wire x1="7.62" y1="-20.32" x2="6.35" y2="-19.05" width="0.3048" layer="94"/>
<wire x1="7.62" y1="-20.32" x2="6.35" y2="-21.59" width="0.3048" layer="94"/>
<wire x1="2.54" y1="-20.32" x2="2.54" y2="-15.24" width="0.3048" layer="94"/>
<wire x1="2.54" y1="-15.24" x2="1.27" y2="-16.51" width="0.3048" layer="94"/>
<wire x1="2.54" y1="-15.24" x2="3.81" y2="-16.51" width="0.3048" layer="94"/>
<text x="8.89" y="-21.082" size="1.778" layer="94">x</text>
<text x="5.08" y="-15.24" size="1.778" layer="94">y</text>
<text x="-1.524" y="14.732" size="1.778" layer="94">3.3V (or 5v)</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="GY-521" prefix="U">
<gates>
<gate name="G$1" symbol="MPU6050" x="-2.54" y="5.08"/>
</gates>
<devices>
<device name="MPU6050" package="GY-521">
<connects>
<connect gate="G$1" pin="ADO" pad="ADO"/>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="INT" pad="INT"/>
<connect gate="G$1" pin="SCL" pad="SCL"/>
<connect gate="G$1" pin="SDA" pad="SDA"/>
<connect gate="G$1" pin="VCC" pad="VCC"/>
<connect gate="G$1" pin="XCL" pad="XCL"/>
<connect gate="G$1" pin="XDA" pad="XDA"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="SI2306">
<packages>
<package name="SI2306">
<smd name="D" x="0" y="2.0066" dx="0.7874" dy="0.889" layer="1" rot="R90"/>
<smd name="S" x="0.9398" y="0" dx="0.7874" dy="0.889" layer="1" rot="R90"/>
<smd name="G" x="-0.9398" y="0" dx="0.7874" dy="0.889" layer="1" rot="R90"/>
<wire x1="1.4605" y1="0.3683" x2="1.4605" y2="1.6383" width="0.127" layer="21"/>
<wire x1="1.4605" y1="1.6383" x2="-1.4605" y2="1.6383" width="0.127" layer="21"/>
<wire x1="-1.4605" y1="1.6383" x2="-1.4605" y2="0.3683" width="0.127" layer="21"/>
<wire x1="-1.4605" y1="0.3683" x2="1.4605" y2="0.3683" width="0.127" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="SI2306">
<circle x="0" y="0" radius="7.62" width="0.254" layer="94"/>
<pin name="D" x="0" y="12.7" length="middle" rot="R270"/>
<pin name="S" x="0" y="-12.7" length="middle" rot="R90"/>
<pin name="G" x="-12.7" y="0" length="middle"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="SI2306">
<gates>
<gate name="G$1" symbol="SI2306" x="0" y="0"/>
</gates>
<devices>
<device name="" package="SI2306">
<connects>
<connect gate="G$1" pin="D" pad="D"/>
<connect gate="G$1" pin="G" pad="G"/>
<connect gate="G$1" pin="S" pad="S"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="1206_resistor">
<packages>
<package name="1206_RESISTOR">
<wire x1="0" y1="0" x2="0" y2="1.5875" width="0.127" layer="21"/>
<wire x1="0" y1="1.5875" x2="3.175" y2="1.5875" width="0.127" layer="21"/>
<wire x1="3.175" y1="1.5875" x2="3.175" y2="0" width="0.127" layer="21"/>
<wire x1="3.175" y1="0" x2="0" y2="0" width="0.127" layer="21"/>
<smd name="2" x="3.429" y="0.79375" dx="1.524" dy="1.016" layer="1" rot="R90"/>
<smd name="1" x="-0.254" y="0.79375" dx="1.524" dy="1.016" layer="1" rot="R90"/>
</package>
</packages>
<symbols>
<symbol name="1206_RESISTOR">
<wire x1="0" y1="0" x2="12.7" y2="0" width="0.254" layer="94"/>
<wire x1="12.7" y1="0" x2="12.7" y2="5.08" width="0.254" layer="94"/>
<wire x1="12.7" y1="5.08" x2="0" y2="5.08" width="0.254" layer="94"/>
<wire x1="0" y1="5.08" x2="0" y2="0" width="0.254" layer="94"/>
<pin name="1" x="-5.08" y="2.54" length="middle"/>
<pin name="2" x="17.78" y="2.54" length="middle" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="1206_RESISTOR">
<gates>
<gate name="G$1" symbol="1206_RESISTOR" x="0" y="-5.08"/>
</gates>
<devices>
<device name="" package="1206_RESISTOR">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="con-lsta" urn="urn:adsk.eagle:library:161">
<description>&lt;b&gt;Female Headers etc.&lt;/b&gt;&lt;p&gt;
Naming:&lt;p&gt;
FE = female&lt;p&gt;
# contacts - # rows&lt;p&gt;
W = angled&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="FE06" urn="urn:adsk.eagle:footprint:8135/1" library_version="2">
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
</packages>
<packages3d>
<package3d name="FE06" urn="urn:adsk.eagle:package:8191/1" type="box" library_version="2">
<description>FEMALE HEADER</description>
<packageinstances>
<packageinstance name="FE06"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="FE06-1" urn="urn:adsk.eagle:symbol:8134/1" library_version="2">
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
</symbols>
<devicesets>
<deviceset name="FE06-1" urn="urn:adsk.eagle:component:8235/2" prefix="SV" uservalue="yes" library_version="2">
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
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:8191/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
<attribute name="POPULARITY" value="11" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="5V_transformer">
<packages>
<package name="5V_TRANSFORMER">
<wire x1="0" y1="0" x2="0" y2="2.8448" width="0.127" layer="21"/>
<wire x1="0" y1="2.8448" x2="0" y2="10.16" width="0.127" layer="21"/>
<wire x1="0" y1="10.16" x2="0" y2="13.0048" width="0.127" layer="21"/>
<wire x1="0" y1="13.0048" x2="16.6878" y2="13.0048" width="0.127" layer="21"/>
<wire x1="16.6878" y1="13.0048" x2="16.6878" y2="0" width="0.127" layer="21"/>
<wire x1="16.6878" y1="0" x2="0" y2="0" width="0.127" layer="21"/>
<smd name="VI-" x="-0.635" y="10.16" dx="2.54" dy="1.778" layer="1" rot="R270"/>
<smd name="VI+" x="-0.635" y="2.8448" dx="2.54" dy="1.778" layer="1" rot="R270"/>
<smd name="VO-" x="17.3228" y="10.16" dx="2.54" dy="1.778" layer="1" rot="R270"/>
<smd name="VO+" x="17.3228" y="2.8448" dx="2.54" dy="1.778" layer="1" rot="R270"/>
</package>
</packages>
<symbols>
<symbol name="5V_TRANSFORMER">
<wire x1="0" y1="0" x2="0" y2="6.35" width="0.254" layer="94"/>
<wire x1="0" y1="6.35" x2="12.7" y2="6.35" width="0.254" layer="94"/>
<wire x1="12.7" y1="6.35" x2="12.7" y2="0" width="0.254" layer="94"/>
<wire x1="12.7" y1="0" x2="0" y2="0" width="0.254" layer="94"/>
<pin name="VI-" x="-5.08" y="5.08" length="middle"/>
<pin name="VI+" x="-5.08" y="1.27" length="middle"/>
<pin name="VO-" x="17.78" y="5.08" length="middle" rot="R180"/>
<pin name="VO+" x="17.78" y="1.27" length="middle" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="5V_TRANSFORMER">
<gates>
<gate name="G$1" symbol="5V_TRANSFORMER" x="0" y="0"/>
</gates>
<devices>
<device name="" package="5V_TRANSFORMER">
<connects>
<connect gate="G$1" pin="VI+" pad="VI+"/>
<connect gate="G$1" pin="VI-" pad="VI-"/>
<connect gate="G$1" pin="VO+" pad="VO+"/>
<connect gate="G$1" pin="VO-" pad="VO-"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="power_main">
<packages>
<package name="POWER_MAIN">
<pad name="VCC" x="1.778" y="1.778" drill="1.016" diameter="2.032"/>
<pad name="GND" x="5.588" y="1.778" drill="1.016" diameter="2.032"/>
<wire x1="0" y1="0" x2="7.366" y2="0" width="0.127" layer="21"/>
<wire x1="7.366" y1="0" x2="7.366" y2="3.556" width="0.127" layer="21"/>
<wire x1="7.366" y1="3.556" x2="0" y2="3.556" width="0.127" layer="21"/>
<wire x1="0" y1="3.556" x2="0" y2="0" width="0.127" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="POWER_MAIN">
<wire x1="0" y1="0" x2="12.7" y2="0" width="0.254" layer="94"/>
<wire x1="12.7" y1="0" x2="12.7" y2="5.08" width="0.254" layer="94"/>
<wire x1="12.7" y1="5.08" x2="0" y2="5.08" width="0.254" layer="94"/>
<wire x1="0" y1="5.08" x2="0" y2="0" width="0.254" layer="94"/>
<pin name="VCC" x="2.54" y="-5.08" length="middle" rot="R90"/>
<pin name="GND" x="10.16" y="-5.08" length="middle" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="POWER_MAIN">
<gates>
<gate name="G$1" symbol="POWER_MAIN" x="0" y="0"/>
</gates>
<devices>
<device name="" package="POWER_MAIN">
<connects>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="VCC" pad="VCC"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="power_motor">
<packages>
<package name="POWER_MOTOR">
<pad name="VCC" x="1.27" y="1.27" drill="0.889" diameter="1.4224"/>
<pad name="DRAIN" x="3.81" y="1.27" drill="0.889" diameter="1.4224"/>
<wire x1="0" y1="0" x2="0" y2="2.54" width="0.127" layer="21"/>
<wire x1="0" y1="2.54" x2="5.08" y2="2.54" width="0.127" layer="21"/>
<wire x1="5.08" y1="2.54" x2="5.08" y2="0" width="0.127" layer="21"/>
<wire x1="5.08" y1="0" x2="0" y2="0" width="0.127" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="POWER_MOTOR">
<wire x1="0" y1="0" x2="12.7" y2="0" width="0.254" layer="94"/>
<wire x1="12.7" y1="0" x2="12.7" y2="5.08" width="0.254" layer="94"/>
<wire x1="12.7" y1="5.08" x2="0" y2="5.08" width="0.254" layer="94"/>
<wire x1="0" y1="5.08" x2="0" y2="0" width="0.254" layer="94"/>
<pin name="VCC" x="2.54" y="-5.08" length="middle" rot="R90"/>
<pin name="DRAIN" x="10.16" y="-5.08" length="middle" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="POWER_MOTOR">
<gates>
<gate name="G$1" symbol="POWER_MOTOR" x="0" y="0"/>
</gates>
<devices>
<device name="" package="POWER_MOTOR">
<connects>
<connect gate="G$1" pin="DRAIN" pad="DRAIN"/>
<connect gate="G$1" pin="VCC" pad="VCC"/>
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
<part name="M1" library="diy-modules" deviceset="ARDUINO-PRO-MINI-*" device="" technology="5.0V"/>
<part name="U1" library="gy-521" deviceset="GY-521" device="MPU6050"/>
<part name="U$1" library="SI2306" deviceset="SI2306" device=""/>
<part name="U$2" library="1206_resistor" deviceset="1206_RESISTOR" device=""/>
<part name="HC-05" library="con-lsta" library_urn="urn:adsk.eagle:library:161" deviceset="FE06-1" device="" package3d_urn="urn:adsk.eagle:package:8191/1"/>
<part name="U$3" library="5V_transformer" deviceset="5V_TRANSFORMER" device=""/>
<part name="U$4" library="power_main" deviceset="POWER_MAIN" device=""/>
<part name="U$5" library="power_motor" deviceset="POWER_MOTOR" device=""/>
<part name="U$6" library="SI2306" deviceset="SI2306" device=""/>
<part name="U$7" library="1206_resistor" deviceset="1206_RESISTOR" device=""/>
<part name="U$8" library="power_motor" deviceset="POWER_MOTOR" device=""/>
<part name="U$9" library="SI2306" deviceset="SI2306" device=""/>
<part name="U$10" library="1206_resistor" deviceset="1206_RESISTOR" device=""/>
<part name="U$11" library="power_motor" deviceset="POWER_MOTOR" device=""/>
<part name="U$12" library="SI2306" deviceset="SI2306" device=""/>
<part name="U$13" library="1206_resistor" deviceset="1206_RESISTOR" device=""/>
<part name="U$14" library="power_motor" deviceset="POWER_MOTOR" device=""/>
<part name="FLUSH" library="con-lsta" library_urn="urn:adsk.eagle:library:161" deviceset="FE06-1" device="" package3d_urn="urn:adsk.eagle:package:8191/1"/>
</parts>
<sheets>
<sheet>
<plain>
<wire x1="115.57" y1="15.24" x2="115.57" y2="82.55" width="0.1524" layer="94"/>
<wire x1="115.57" y1="82.55" x2="238.76" y2="82.55" width="0.1524" layer="94"/>
<wire x1="238.76" y1="82.55" x2="238.76" y2="15.24" width="0.1524" layer="94"/>
<wire x1="238.76" y1="15.24" x2="115.57" y2="15.24" width="0.1524" layer="94"/>
<wire x1="0" y1="0" x2="113.03" y2="0" width="0.1524" layer="94"/>
<wire x1="113.03" y1="0" x2="113.03" y2="82.55" width="0.1524" layer="94"/>
<wire x1="113.03" y1="82.55" x2="0" y2="82.55" width="0.1524" layer="94"/>
<wire x1="0" y1="82.55" x2="0" y2="0" width="0.1524" layer="94"/>
<wire x1="0" y1="111.76" x2="66.04" y2="111.76" width="0.1524" layer="94"/>
<wire x1="66.04" y1="111.76" x2="66.04" y2="85.09" width="0.1524" layer="94"/>
<wire x1="66.04" y1="85.09" x2="0" y2="85.09" width="0.1524" layer="94"/>
<wire x1="0" y1="85.09" x2="0" y2="111.76" width="0.1524" layer="94"/>
</plain>
<instances>
<instance part="M1" gate="G$1" x="33.02" y="33.02" smashed="yes">
<attribute name="NAME" x="48.26" y="60.96" size="1.778" layer="95"/>
<attribute name="VALUE" x="48.26" y="58.42" size="1.778" layer="96"/>
</instance>
<instance part="U1" gate="G$1" x="92.71" y="38.1" smashed="yes"/>
<instance part="U$1" gate="G$1" x="137.16" y="52.07" smashed="yes"/>
<instance part="U$2" gate="G$1" x="123.19" y="34.29" smashed="yes" rot="R90"/>
<instance part="HC-05" gate="G$1" x="97.79" y="72.39" smashed="yes" rot="R180">
<attribute name="VALUE" x="99.06" y="82.55" size="1.778" layer="96" rot="R180"/>
<attribute name="NAME" x="99.06" y="61.468" size="1.778" layer="95" rot="R180"/>
</instance>
<instance part="U$3" gate="G$1" x="34.29" y="95.25" smashed="yes"/>
<instance part="U$4" gate="G$1" x="2.54" y="102.87" smashed="yes"/>
<instance part="U$5" gate="G$1" x="127" y="72.39" smashed="yes"/>
<instance part="U$6" gate="G$1" x="167.64" y="52.07" smashed="yes"/>
<instance part="U$7" gate="G$1" x="153.67" y="34.29" smashed="yes" rot="R90"/>
<instance part="U$8" gate="G$1" x="157.48" y="72.39" smashed="yes"/>
<instance part="U$9" gate="G$1" x="198.12" y="52.07" smashed="yes"/>
<instance part="U$10" gate="G$1" x="184.15" y="34.29" smashed="yes" rot="R90"/>
<instance part="U$11" gate="G$1" x="187.96" y="72.39" smashed="yes"/>
<instance part="U$12" gate="G$1" x="228.6" y="52.07" smashed="yes"/>
<instance part="U$13" gate="G$1" x="214.63" y="34.29" smashed="yes" rot="R90"/>
<instance part="U$14" gate="G$1" x="218.44" y="72.39" smashed="yes"/>
<instance part="FLUSH" gate="G$1" x="30.48" y="78.74" smashed="yes" rot="R270">
<attribute name="VALUE" x="20.32" y="80.01" size="1.778" layer="96" rot="R270"/>
<attribute name="NAME" x="41.402" y="80.01" size="1.778" layer="95" rot="R270"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="SCL" class="0">
<segment>
<pinref part="M1" gate="G$1" pin="A5"/>
<wire x1="50.8" y1="53.34" x2="55.88" y2="53.34" width="0.1524" layer="91"/>
<label x="55.88" y="53.34" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="G$1" pin="SCL"/>
<wire x1="77.47" y1="43.18" x2="72.39" y2="43.18" width="0.1524" layer="91"/>
<label x="72.39" y="43.18" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="SDA" class="0">
<segment>
<pinref part="M1" gate="G$1" pin="A4"/>
<wire x1="50.8" y1="50.8" x2="55.88" y2="50.8" width="0.1524" layer="91"/>
<label x="55.88" y="50.8" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="G$1" pin="SDA"/>
<wire x1="77.47" y1="38.1" x2="72.39" y2="38.1" width="0.1524" layer="91"/>
<label x="72.39" y="38.1" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="VI-"/>
<wire x1="29.21" y1="100.33" x2="24.13" y2="100.33" width="0.1524" layer="91"/>
<label x="24.13" y="100.33" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U$3" gate="G$1" pin="VO-"/>
<wire x1="52.07" y1="100.33" x2="57.15" y2="100.33" width="0.1524" layer="91"/>
<label x="57.15" y="100.33" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="M1" gate="G$1" pin="GND.2"/>
<wire x1="50.8" y1="43.18" x2="55.88" y2="43.18" width="0.1524" layer="91"/>
<label x="55.88" y="43.18" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="G$1" pin="GND"/>
<wire x1="77.47" y1="48.26" x2="72.39" y2="48.26" width="0.1524" layer="91"/>
<label x="72.39" y="48.26" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U$1" gate="G$1" pin="S"/>
<wire x1="137.16" y1="39.37" x2="137.16" y2="34.29" width="0.1524" layer="91"/>
<label x="137.16" y="34.29" size="1.27" layer="95" rot="R270" xref="yes"/>
</segment>
<segment>
<pinref part="U$4" gate="G$1" pin="GND"/>
<wire x1="12.7" y1="97.79" x2="12.7" y2="92.71" width="0.1524" layer="91"/>
<label x="12.7" y="92.71" size="1.27" layer="95" rot="R270" xref="yes"/>
</segment>
<segment>
<pinref part="U$2" gate="G$1" pin="1"/>
<wire x1="120.65" y1="29.21" x2="120.65" y2="24.13" width="0.1524" layer="91"/>
<label x="120.65" y="24.13" size="1.27" layer="95" rot="R270" xref="yes"/>
</segment>
<segment>
<pinref part="U$6" gate="G$1" pin="S"/>
<wire x1="167.64" y1="39.37" x2="167.64" y2="34.29" width="0.1524" layer="91"/>
<label x="167.64" y="34.29" size="1.27" layer="95" rot="R270" xref="yes"/>
</segment>
<segment>
<pinref part="U$7" gate="G$1" pin="1"/>
<wire x1="151.13" y1="29.21" x2="151.13" y2="24.13" width="0.1524" layer="91"/>
<label x="151.13" y="24.13" size="1.27" layer="95" rot="R270" xref="yes"/>
</segment>
<segment>
<pinref part="U$9" gate="G$1" pin="S"/>
<wire x1="198.12" y1="39.37" x2="198.12" y2="34.29" width="0.1524" layer="91"/>
<label x="198.12" y="34.29" size="1.27" layer="95" rot="R270" xref="yes"/>
</segment>
<segment>
<pinref part="U$10" gate="G$1" pin="1"/>
<wire x1="181.61" y1="29.21" x2="181.61" y2="24.13" width="0.1524" layer="91"/>
<label x="181.61" y="24.13" size="1.27" layer="95" rot="R270" xref="yes"/>
</segment>
<segment>
<pinref part="U$12" gate="G$1" pin="S"/>
<wire x1="228.6" y1="39.37" x2="228.6" y2="34.29" width="0.1524" layer="91"/>
<label x="228.6" y="34.29" size="1.27" layer="95" rot="R270" xref="yes"/>
</segment>
<segment>
<pinref part="U$13" gate="G$1" pin="1"/>
<wire x1="212.09" y1="29.21" x2="212.09" y2="24.13" width="0.1524" layer="91"/>
<label x="212.09" y="24.13" size="1.27" layer="95" rot="R270" xref="yes"/>
</segment>
<segment>
<pinref part="HC-05" gate="G$1" pin="3"/>
<wire x1="90.17" y1="72.39" x2="85.09" y2="72.39" width="0.1524" layer="91"/>
<label x="85.09" y="72.39" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="M1" gate="G$1" pin="GND.1"/>
<wire x1="15.24" y1="38.1" x2="10.16" y2="38.1" width="0.1524" layer="91"/>
<label x="10.16" y="38.1" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="VIN" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="VI+"/>
<wire x1="29.21" y1="96.52" x2="24.13" y2="96.52" width="0.1524" layer="91"/>
<label x="24.13" y="96.52" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="U$4" gate="G$1" pin="VCC"/>
<wire x1="5.08" y1="97.79" x2="5.08" y2="92.71" width="0.1524" layer="91"/>
<label x="5.08" y="92.71" size="1.27" layer="95" rot="R270" xref="yes"/>
</segment>
<segment>
<pinref part="U$5" gate="G$1" pin="VCC"/>
<wire x1="129.54" y1="67.31" x2="129.54" y2="62.23" width="0.1524" layer="91"/>
<label x="129.54" y="62.23" size="1.27" layer="95" rot="R270" xref="yes"/>
</segment>
<segment>
<pinref part="U$8" gate="G$1" pin="VCC"/>
<wire x1="160.02" y1="67.31" x2="160.02" y2="62.23" width="0.1524" layer="91"/>
<label x="160.02" y="62.23" size="1.27" layer="95" rot="R270" xref="yes"/>
</segment>
<segment>
<pinref part="U$11" gate="G$1" pin="VCC"/>
<wire x1="190.5" y1="67.31" x2="190.5" y2="62.23" width="0.1524" layer="91"/>
<label x="190.5" y="62.23" size="1.27" layer="95" rot="R270" xref="yes"/>
</segment>
<segment>
<pinref part="U$14" gate="G$1" pin="VCC"/>
<wire x1="220.98" y1="67.31" x2="220.98" y2="62.23" width="0.1524" layer="91"/>
<label x="220.98" y="62.23" size="1.27" layer="95" rot="R270" xref="yes"/>
</segment>
</net>
<net name="5V" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="VO+"/>
<wire x1="52.07" y1="96.52" x2="57.15" y2="96.52" width="0.1524" layer="91"/>
<label x="57.15" y="96.52" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="M1" gate="G$1" pin="RAW"/>
<wire x1="50.8" y1="45.72" x2="55.88" y2="45.72" width="0.1524" layer="91"/>
<label x="55.88" y="45.72" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="U$5" gate="G$1" pin="DRAIN"/>
<pinref part="U$1" gate="G$1" pin="D"/>
<wire x1="137.16" y1="67.31" x2="137.16" y2="64.77" width="0.1524" layer="91"/>
</segment>
</net>
<net name="D3" class="0">
<segment>
<pinref part="U$2" gate="G$1" pin="2"/>
<pinref part="U$1" gate="G$1" pin="G"/>
<wire x1="120.65" y1="52.07" x2="124.46" y2="52.07" width="0.1524" layer="91"/>
<wire x1="120.65" y1="52.07" x2="120.65" y2="57.15" width="0.1524" layer="91"/>
<junction x="120.65" y="52.07"/>
<label x="120.65" y="57.15" size="1.27" layer="95" rot="R90" xref="yes"/>
</segment>
<segment>
<pinref part="M1" gate="G$1" pin="D3"/>
<wire x1="15.24" y1="33.02" x2="10.16" y2="33.02" width="0.1524" layer="91"/>
<label x="10.16" y="33.02" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="U$8" gate="G$1" pin="DRAIN"/>
<pinref part="U$6" gate="G$1" pin="D"/>
<wire x1="167.64" y1="67.31" x2="167.64" y2="64.77" width="0.1524" layer="91"/>
</segment>
</net>
<net name="D9" class="0">
<segment>
<pinref part="U$7" gate="G$1" pin="2"/>
<pinref part="U$6" gate="G$1" pin="G"/>
<wire x1="151.13" y1="52.07" x2="154.94" y2="52.07" width="0.1524" layer="91"/>
<wire x1="151.13" y1="52.07" x2="151.13" y2="57.15" width="0.1524" layer="91"/>
<junction x="151.13" y="52.07"/>
<label x="151.13" y="57.15" size="1.27" layer="95" rot="R90" xref="yes"/>
</segment>
<segment>
<pinref part="M1" gate="G$1" pin="D9"/>
<wire x1="15.24" y1="17.78" x2="10.16" y2="17.78" width="0.1524" layer="91"/>
<label x="10.16" y="17.78" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="U$11" gate="G$1" pin="DRAIN"/>
<pinref part="U$9" gate="G$1" pin="D"/>
<wire x1="198.12" y1="67.31" x2="198.12" y2="64.77" width="0.1524" layer="91"/>
</segment>
</net>
<net name="D10" class="0">
<segment>
<pinref part="U$10" gate="G$1" pin="2"/>
<pinref part="U$9" gate="G$1" pin="G"/>
<wire x1="181.61" y1="52.07" x2="185.42" y2="52.07" width="0.1524" layer="91"/>
<wire x1="181.61" y1="52.07" x2="181.61" y2="57.15" width="0.1524" layer="91"/>
<junction x="181.61" y="52.07"/>
<label x="181.61" y="57.15" size="1.27" layer="95" rot="R90" xref="yes"/>
</segment>
<segment>
<pinref part="M1" gate="G$1" pin="D10"/>
<wire x1="50.8" y1="17.78" x2="55.88" y2="17.78" width="0.1524" layer="91"/>
<label x="55.88" y="17.78" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="U$14" gate="G$1" pin="DRAIN"/>
<pinref part="U$12" gate="G$1" pin="D"/>
<wire x1="228.6" y1="67.31" x2="228.6" y2="64.77" width="0.1524" layer="91"/>
</segment>
</net>
<net name="D11" class="0">
<segment>
<pinref part="U$13" gate="G$1" pin="2"/>
<pinref part="U$12" gate="G$1" pin="G"/>
<wire x1="212.09" y1="52.07" x2="215.9" y2="52.07" width="0.1524" layer="91"/>
<wire x1="212.09" y1="52.07" x2="212.09" y2="57.15" width="0.1524" layer="91"/>
<junction x="212.09" y="52.07"/>
<label x="212.09" y="57.15" size="1.27" layer="95" rot="R90" xref="yes"/>
</segment>
<segment>
<pinref part="M1" gate="G$1" pin="D11"/>
<wire x1="50.8" y1="20.32" x2="55.88" y2="20.32" width="0.1524" layer="91"/>
<label x="55.88" y="20.32" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="VCC" class="0">
<segment>
<pinref part="M1" gate="G$1" pin="VCC"/>
<wire x1="50.8" y1="38.1" x2="55.88" y2="38.1" width="0.1524" layer="91"/>
<label x="55.88" y="38.1" size="1.27" layer="95" xref="yes"/>
</segment>
<segment>
<pinref part="U1" gate="G$1" pin="VCC"/>
<wire x1="77.47" y1="53.34" x2="72.39" y2="53.34" width="0.1524" layer="91"/>
<label x="72.39" y="53.34" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="HC-05" gate="G$1" pin="2"/>
<wire x1="90.17" y1="74.93" x2="85.09" y2="74.93" width="0.1524" layer="91"/>
<label x="85.09" y="74.93" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="N$1" class="0">
<segment>
<pinref part="FLUSH" gate="G$1" pin="1"/>
<pinref part="M1" gate="G$1" pin="P_DTR"/>
<wire x1="25.4" y1="71.12" x2="25.4" y2="68.58" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="FLUSH" gate="G$1" pin="2"/>
<pinref part="M1" gate="G$1" pin="P_TXD"/>
<wire x1="27.94" y1="71.12" x2="27.94" y2="68.58" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="FLUSH" gate="G$1" pin="3"/>
<pinref part="M1" gate="G$1" pin="P_RXD"/>
<wire x1="30.48" y1="71.12" x2="30.48" y2="68.58" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="FLUSH" gate="G$1" pin="4"/>
<pinref part="M1" gate="G$1" pin="P_VCC"/>
<wire x1="33.02" y1="71.12" x2="33.02" y2="68.58" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$9" class="0">
<segment>
<pinref part="FLUSH" gate="G$1" pin="5"/>
<pinref part="M1" gate="G$1" pin="P_CTS"/>
<wire x1="35.56" y1="71.12" x2="35.56" y2="68.58" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$10" class="0">
<segment>
<pinref part="FLUSH" gate="G$1" pin="6"/>
<pinref part="M1" gate="G$1" pin="P_GND"/>
<wire x1="38.1" y1="71.12" x2="38.1" y2="68.58" width="0.1524" layer="91"/>
</segment>
</net>
<net name="B_TXD" class="0">
<segment>
<pinref part="HC-05" gate="G$1" pin="4"/>
<wire x1="90.17" y1="69.85" x2="85.09" y2="69.85" width="0.1524" layer="91"/>
<label x="85.09" y="69.85" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="M1" gate="G$1" pin="D0/RX"/>
<wire x1="15.24" y1="43.18" x2="10.16" y2="43.18" width="0.1524" layer="91"/>
<label x="10.16" y="43.18" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="B_RXD" class="0">
<segment>
<pinref part="HC-05" gate="G$1" pin="5"/>
<wire x1="90.17" y1="67.31" x2="85.09" y2="67.31" width="0.1524" layer="91"/>
<label x="85.09" y="67.31" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="M1" gate="G$1" pin="D1/TX"/>
<wire x1="15.24" y1="45.72" x2="10.16" y2="45.72" width="0.1524" layer="91"/>
<label x="10.16" y="45.72" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
<errors>
<approved hash="104,1,45.72,46.99,M1,RAW,5V,,,"/>
<approved hash="104,1,45.72,44.45,M1,GND.2,GND,,,"/>
<approved hash="113,1,94.2696,104.182,HC-05,,,,,"/>
<approved hash="113,1,28.2296,74.9723,HC-01,,,,,"/>
</errors>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
