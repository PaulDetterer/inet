package inet.work.EnvMon;

import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;                            
import inet.node.ethernet.Eth100M;
import inet.node.inet.SensorNode;
import inet.node.inet.StandardHost;
import inet.node.inet.WirelessHost;
import inet.physicallayer.apskradio.packetlevel.ApskScalarRadioMedium;                         
import inet.physicallayer.ieee802154.bitlevel.Ieee802154UwbIrRadioMedium;                      
import inet.physicallayer.ieee802154.packetlevel.Ieee802154NarrowbandScalarRadioMedium;        
import inet.visualizer.integrated.IntegratedMultiVisualizer;                                   
import inet.visualizer.integrated.IntegratedVisualizer;                                        
                                                                                               
    
network EnvMonNet                                                                              
{       
//    parameters:
//        int size = 53;                                                                         
    @display("bgb=400,250;");                                         
    submodules:
       node0: SensorNode {
            @display("p=301.36054421768705,25.396825396825395;i=misc/sensor");
        } 
       node1: SensorNode {
            @display("p=297.50566893424036,28.798185941043084;i=misc/sensor");
        } 
       node2: SensorNode {
            @display("p=290.9297052154195,39.002267573696145;i=misc/sensor");
        } 
       node3: SensorNode {
            @display("p=284.12698412698415,44.89795918367348;i=misc/sensor");
        } 
       node4: SensorNode {
            @display("p=278.00453514739235,54.195011337868486;i=misc/sensor");
        } 
       node5: SensorNode {
            @display("p=262.81179138322,57.59637188208617;i=misc/sensor");
        } 
       node6: SensorNode {
            @display("p=252.38095238095238,39.229024943310655;i=misc/sensor");
        } 
       node7: SensorNode {
            @display("p=268.2539682539682,56.916099773242635;i=misc/sensor");
        } 
       node8: SensorNode {
            @display("p=198.63945578231295,44.89795918367348;i=misc/sensor");
        } 
       node9: SensorNode {
            @display("p=203.62811791383223,52.15419501133787;i=misc/sensor");
        } 
       node10: SensorNode {
            @display("p=174.6031746031746,63.71882086167801;i=misc/sensor");
        } 
       node11: SensorNode {
            @display("p=165.75963718820864,74.82993197278911;i=misc/sensor");
        } 
       node12: SensorNode {
            @display("p=158.73015873015876,98.18594104308391;i=misc/sensor");
        } 
       node13: SensorNode {
            @display("p=136.73469387755102,149.65986394557822;i=misc/sensor");
        } 
       node14: SensorNode {
            @display("p=123.12925170068029,135.14739229024943;i=misc/sensor");
        } 
       node15: SensorNode {
            @display("p=118.14058956916101,134.4671201814059;i=misc/sensor");
        } 
       node16: SensorNode {
            @display("p=148.9795918367347,128.57142857142858;i=misc/sensor");
        } 
       node17: SensorNode {
            @display("p=117.00680272108845,130.15873015873018;i=misc/sensor");
        } 
       node18: SensorNode {
            @display("p=112.92517006802723,129.70521541950114;i=misc/sensor");
        } 
       node19: SensorNode {
            @display("p=116.55328798185941,126.30385487528346;i=misc/sensor");
        } 
       node20: SensorNode {
            @display("p=111.56462585034012,125.62358276643992;i=misc/sensor");
        } 
       node21: SensorNode {
            @display("p=112.92517006802723,139.22902494331066;i=misc/sensor");
        } 
       node22: SensorNode {
            @display("p=107.48299319727893,134.01360544217687;i=misc/sensor");
        } 
       node23: SensorNode {
            @display("p=106.12244897959184,141.26984126984127;i=misc/sensor");
        } 
       node24: SensorNode {
            @display("p=103.17460317460318,129.2517006802721;i=misc/sensor");
        } 
       node25: SensorNode {
            @display("p=119.72789115646259,114.28571428571429;i=misc/sensor");
        } 
       node26: SensorNode {
            @display("p=123.58276643990929,119.27437641723355;i=misc/sensor");
        } 
       node27: SensorNode {
            @display("p=83.44671201814059,135.60090702947846;i=misc/sensor");
        } 
       node28: SensorNode {
            @display("p=79.13832199546486,138.0952380952381;i=misc/sensor");
        } 
       node29: SensorNode {
            @display("p=62.81179138321996,131.97278911564626;i=misc/sensor");
        } 
       node30: SensorNode {
            @display("p=40.58956916099773,127.89115646258504;i=misc/sensor");
        } 
       node31: SensorNode {
            @display("p=33.333333333333336,129.2517006802721;i=misc/sensor");
        } 
       node32: SensorNode {
            @display("p=36.054421768707485,124.03628117913831;i=misc/sensor");
        } 
       node33: SensorNode {
            @display("p=27.43764172335601,133.78684807256238;i=misc/sensor");
        } 
       node34: SensorNode {
            @display("p=16.553287981859413,134.69387755102042;i=misc/sensor");
        } 
       node35: SensorNode {
            @display("p=18.594104308390023,128.11791383219955;i=misc/sensor");
        } 
       node36: SensorNode {
            @display("p=13.605442176870747,130.38548752834467;i=misc/sensor");
        } 
       node37: SensorNode {
            @display("p=17.460317460317462,123.58276643990929;i=misc/sensor");
        } 
       node38: SensorNode {
            @display("p=12.698412698412698,124.48979591836735;i=misc/sensor");
        } 
       node39: SensorNode {
            @display("p=37.86848072562359,144.89795918367346;i=misc/sensor");
        } 
       node40: SensorNode {
            @display("p=42.17687074829932,143.5374149659864;i=misc/sensor");
        } 
       node41: SensorNode {
            @display("p=45.35147392290249,146.48526077097506;i=misc/sensor");
        } 
       node42: SensorNode {
            @display("p=47.39229024943311,136.96145124716554;i=misc/sensor");
        } 
       node43: SensorNode {
            @display("p=188.20861678004536,96.82539682539682;i=misc/sensor");
        } 
       node44: SensorNode {
            @display("p=182.08616780045352,102.94784580498867;i=misc/sensor");
        } 
       node45: SensorNode {
            @display("p=189.11564625850343,112.69841269841272;i=misc/sensor");
        } 
       node46: SensorNode {
            @display("p=180.72562358276645,117.46031746031748;i=misc/sensor");
        } 
       node47: SensorNode {
            @display("p=30.38548752834467,100.90702947845806;i=misc/sensor");
        } 
       node48: SensorNode {
            @display("p=53.06122448979592,84.12698412698414;i=misc/sensor");
        } 
       node49: SensorNode {
            @display("p=48.52607709750568,112.47165532879819;i=misc/sensor");
        } 
       node50: SensorNode {
            @display("p=57.59637188208617,97.27891156462586;i=misc/sensor");
        } 
       node51: SensorNode {
            @display("p=63.4920634920635,120.63492063492063;i=misc/sensor");
        } 
       node52: SensorNode {
            @display("p=69.84126984126985,107.2562358276644;i=misc/sensor");
        } 

        configurator: Ipv4NetworkConfigurator {                                                
        }
        radioMedium: Ieee802154NarrowbandScalarRadioMedium {                                   
        }
        visualizer: IntegratedMultiVisualizer;
}           
