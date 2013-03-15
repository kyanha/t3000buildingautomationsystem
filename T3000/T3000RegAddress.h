#pragma once

const int T3000_5ABCDFG_LED_ADDRESS = 1;
const int T3000_5EH_LCD_ADDRESS = 2;
const int T3000_6_ADDRESS = 3;

//UCHAR Mdb_Adress_Map;

class T3000RegAddress
{
public:
	T3000RegAddress(void);
	~T3000RegAddress(void);
	_RecordsetPtr m_pRs;
	_ConnectionPtr m_pCon;
	bool MatchMoudleAddress(void);
private:

	// bool MatchName(CString strName , int Addressvalue);

public:

	

	//int MODBUS_TEMPRATURE_CHIP;


	//int   MODBUS_SERIALNUMBER_LOWORD;//              // -	-	Lower 2 bytes of the serial number
	//int	MODBUS_SERIALNUMBER_HIWORD;//  = 2   		// -	-	Upper 2 bytes of teh serial number
	//int	MODBUS_VERSION_NUMBER_LO;//   = 4   		// -	-	Software version
	//int	MODBUS_VERSION_NUMBER_HI;//				// -	-	Software version
	//int	MODBUS_ADDRESS;//							// 1	254	Device modbus address
	//int	MODBUS_PRODUCT_MODEL;// 					// -	-	Temco Product Model	1=Tstat5B  2=Tstat5A  4=Tstat5C  12=Tstat5D  
	//int	MODBUS_HARDWARE_REV;// 					// -	-	Hardware Revision	 
	//int	MODBUS_PIC_VERSION;// 						// -	-	PIC firmware version
	//int	MODBUS_ADDRESS_PLUG_N_PLAY;// 				// -	-	Temporary address for plug-n-play addressing scheme
	//int	MODBUS_CUSTOM_ADDRESS;// 	= 14 			// custom register
	//int	MODBUS_BASE_ADDRESS;// 	= 15 			// base address select// registers needed for updating status
	//int	MODBUS_UPDATE_STATUS;//	= 16 			// reg 16 status for update_flash// writing 0x7F means jump to ISP routine// writing 0x8F means completely erase eeprom
	//int	MODBUS_UPDATE_PTR_HI;// 					// reg 17 pointer for last attempt upload HI
	//int	MODBUS_UPDATE_PTR_LO;// 					// reg 18 pointer for last attempt upload LO
	//int	MODBUS_SCRATCHPAD_ADDRESS;//   			// -	-	Internal scratch pad address


	//int	MODBUS_COOLING_VALVE;                    // -	-	Cooling valve position 0-1000 = 0-10V
	//int	MODBUS_HEATING_VALVE ;                  // -	-	Heating valve position 0-1000 = 0-10V
	//int	MODBUS_COOLING_PID 		;				// -	-	Cooling PI Term	0-100 - PID IN REV25
	//int	MODBUS_HEATING_PID 		;				// -	-	Heating PI Term	0-1000 - NOT USED IN REV25
	//int	MODBUS_COOL_HEAT_MODE 	;				// -	-	Heating or cooling mode in effect	0 = coasting  1 = cooling  2 = heating
	//int	MODBUS_MODE_OPERATION 	;				// -	-	Current state of Tstat.  High heat -> coasting -> high cool.  //		0 = Coasting  1 = Cooling1  2 = Cooling2  3 = Cooling3  4 = Heating1  5 = Heating2  6 = Heating3 											
	//int	MODBUS_DIGITAL_OUTPUT_STATUS 	;		// -	-	Relays 1 2 3 and  if on-off type  4 and 5
	//int	MODBUS_CALIBRATION    	   		;		// 109 0	255	Thermistor calibration term 											//		0 = Temperature - 12.5 degrees  125 = Temperature + 0 degrees  255 = Temperature + 13 degrees	// Address 110 
	//int	MODBUS_CALIBRATION_ANALOG_IN1  	;		// 0	255	External thermistor calibration term  //		0 = Temperature - 12.5 degrees  125 = Temperature + 0 degrees  255 = Temperature + 13 degrees											
	//int	MODBUS_TEMP_SELECT   			;		// 0	1= external sensor analog input 1   2 = internal thermistor  3 = average the internal thermistor and analog input1
	//int	MODBUS_DAC_OFFSET 				;		// 0	255	DAC voltage offset
	//int	MODBUS_DELAY 					;		// 0	120	Short cycle prevention delay	(0.1 seconds) - NOT USED IN REV25
	//int	MODBUS_COOLING_PTERM        	;		// 0	255	Cooling P term (0.1 degree)
	//int	MODBUS_COOLING_ITERM    		;		// 0	255	Cooling I term (0.1 %deg/min)
	//int	MODBUS_HEATING_PTERM        	;		// 0	255	Heating P term (0.1 degree) - NOT USED IN REV25
	//int	MODBUS_HEATING_ITERM    		;		// 0	50	Heating I term (1 %deg/min) - NOT USED IN REV25
	//int	MODBUS_SEQUENCE   				;		// 0	2	Sequence of operation   tstat behaves differently according to sequence
	//int	MODBUS_COOLING_DEADBAND      	;		// 1	100	Cooling deadband	(0.1 degree)
	//int	MODBUS_HEATING_DEADBAND     	;		// 1	100	Heating deadband	(0.1 degree)
	//int	MODBUS_DEGC_OR_F      			;		// 0	1	Temperature units  0 = DegC  1 = DegF 
	//int	MODBUS_FAN_MODE    				;		// 0	3	Number of fan speeds to show on the display 0 = 0 speeds  3 = 3 speeds
	//int	MODBUS_NIGHT_HEATING_DEADBAND  	;		// 0	35	(0 and 95 for degrees F)	Night heating setback (1 degree)
	//int	MODBUS_NIGHT_COOLING_DEADBAND   ;		// 0	99	(0 and 95 for degrees F)	Night cooling setback (1 degree)
	//int	MODBUS_APPLICATION    ;
	//int	MODBUS_POWERUP_SETPOINT;   				// 15	50	(59 and 99 for degrees F)	Power up cooling setpoint (1 degree)
	//int	MODBUS_POWERUP_MODE   	;				// 0	3	Powerup mode.  0=Off  2=On  2=Last Value  3=Auto
	//int	MODBUS_KEYPAD_SELECT  	;				// 0	3	Number of buttons on the keypad - 0=2  1=4  2=6A  3=6B 
	//int	MODBUS_AUTO_ONLY  		;				// 0	1	Enable or disable manual modes.  0=manual allowed  1=auto only 2 = DDC mode
	//int	MODBUS_OUTPUT_SCALE    	;				// 0	7	Sets the full scale voltage of the outputs - NOT USED IN REV25	//		0=ON/OFF  1=0-10V  2=0-5V  3=2-10V  4=OFF/ON  5=10-0V  6=5-0V  7=10-2V				    						
	//int	MODBUS_MAX_SETPOINT      ;       		// 10	99	(50 and 150 for degrees F)	Max cooling setpoint (1degree)
	//int	MODBUS_MIN_SETPOINT 		;			// 10	99	(50 and 150 for degrees F)	Min heating setpoint (1degree)
	//int	MODBUS_SPECIAL_MENU_LOCK 	;			// 0	1	Special menu lockout via keypad  serial port only 0=unlock  1=lock	
	//int	MODBUS_FACTORY_DEFAULTS      ;			// 0	1	Factory defaults  0=no default
	//int	MODBUS_COOLING_SETPOINT 		;		// 15	50	(59 and 99 for degrees F)	Cooling setpoint (1degree)
	//int	MODBUS_HEATING_SETPOINT   		;		// 10	35	(50 and 95 for degrees F)	Heating setpoint (1degree)
	//int	MODBUS_FAN_SPEED    			;		// 0	4	Fan speed 0=OFF  1=Low  2=MED  3=HI  4=AUTO
	//int	MODBUS_FAN0_OPER_TABLE_COAST     ;  	// 1 byte  first 5 lsb shows the relay states  last 3 msb are spares
	//int	MODBUS_FAN0_OPER_TABLE_COOL1 		;// 1st byte is always coasting
	//int	MODBUS_FAN0_OPER_TABLE_COOL2       	;// next is cooling stages 
	//int	MODBUS_FAN0_OPER_TABLE_COOL3       	;// then comes heating stages
	//int	MODBUS_FAN0_OPER_TABLE_HEAT1      ; 	// there are up to 7 stages  unused stages are pushed to the end of the strucuture  spare if not used
	//int	MODBUS_FAN0_OPER_TABLE_HEAT2       ;	// any of the stages can be heat or cool depending on the number of heat and cool stages  
	//int	MODBUS_FAN0_OPER_TABLE_HEAT3       ;	// defined in registers 276 and 277
	//int	MODBUS_FAN1_OPER_TABLE_COAST       ;	// Address 145
	//int	MODBUS_FAN1_OPER_TABLE_COOL1 	;	// 
	//int	MODBUS_FAN1_OPER_TABLE_COOL2     ;  	// 
	//int	MODBUS_FAN1_OPER_TABLE_COOL3      ; 	// 
	//int	MODBUS_FAN1_OPER_TABLE_HEAT1       ;	// 
	//int	MODBUS_FAN1_OPER_TABLE_HEAT2       	;// 
	//int	MODBUS_FAN1_OPER_TABLE_HEAT3       	;// 		
	//int	MODBUS_FAN2_OPER_TABLE_COAST       	;// Address 152
	//int	MODBUS_FAN2_OPER_TABLE_COOL1 		;// 
	//int	MODBUS_FAN2_OPER_TABLE_COOL2       	;// 
	//int	MODBUS_FAN2_OPER_TABLE_COOL3       	;// 
	//int	MODBUS_FAN2_OPER_TABLE_HEAT1       	;// 
	//int	MODBUS_FAN2_OPER_TABLE_HEAT2       	;// 
	//int	MODBUS_FAN2_OPER_TABLE_HEAT3       	;// 			
	//int	MODBUS_FAN3_OPER_TABLE_COAST       	;// Address 159
	//int	MODBUS_FAN3_OPER_TABLE_COOL1 		;// 
	//int	MODBUS_FAN3_OPER_TABLE_COOL2       	;// 
	//int	MODBUS_FAN3_OPER_TABLE_COOL3       	;// 
	//int	MODBUS_FAN3_OPER_TABLE_HEAT1   ;    	// 
	//int	MODBUS_FAN3_OPER_TABLE_HEAT2;       	// 
	//int	MODBUS_FAN3_OPER_TABLE_HEAT3 ;      	// 		
	//int	MODBUS_FANAUT_OPER_TABLE_COAST;      // Address 166
	//int	MODBUS_FANAUT_OPER_TABLE_COOL1 	;	// 
	//int	MODBUS_FANAUT_OPER_TABLE_COOL2   ;   // 
	//int	MODBUS_FANAUT_OPER_TABLE_COOL3    ;  // 
	//int	MODBUS_FANAUT_OPER_TABLE_HEAT1    ;  // 
	//int	MODBUS_FANAUT_OPER_TABLE_HEAT2    ;  // 
	//int	MODBUS_FANAUT_OPER_TABLE_HEAT3    ;  // 
	//int	MODBUS_VALVE_OPERATION_TABLE_BEGIN; 	// Address 173 
	//int	MODBUS_VALVE_OPER_TABLE_COOL1 ;
	//int	MODBUS_VALVE_OPER_TABLE_COOL2 ;
	//int	MODBUS_VALVE_OPER_TABLE_COOL3 ;
	//int	MODBUS_VALVE_OPER_TABLE_HEAT1 ;
	//int	MODBUS_VALVE_OPER_TABLE_HEAT2 ;
	//int	MODBUS_VALVE_OPER_TABLE_HEAT3 ;
	//int	MODBUS_EXTERNAL_SENSOR_0 		;		// -	-	External Sensor 0 reading
	//int	MODBUS_EXTERNAL_SENSOR_1 		;		// -	-	External Sensor 1 reading
	//int	MODBUS_NIGHT_HEATING_SETPOINT 	;		// 10	99	Night Heating Setpoint	(1 degree)
	//int	MODBUS_NIGHT_COOLING_SETPOINT 	;		// 10	99	Night Cooling Setpoint	(1 degree)
	//int	MODBUS_INFO_BYTE 				;		// -	-	Byte that holds info about the tstat //bit0 = occupancy bit - 1=occupied  0=unoccupied //bit1 = watchdog reset - 1 indicates a reset due to watchdog //bit2 = serial write reset prevention
	//int	MODBUS_BAUDRATE 				;		// 0	1	Baudrate 0 = 9.6kb/s  1 = 19.2kb/s
	//int	MODBUS_OUTPUT1_SCALE 			;		// 0	3	Sets the full scale voltage of analog output 1											//		0=ON/OFF  1=0-10V  2=0-5V  3=2-10V  
	//int	MODBUS_OUTPUT2_SCALE 			;		// 0	3	Sets the full scale voltage of analog output 2    										//		0=ON/OFF  1=0-10V  2=0-5V  3=2-10V  
	//int	MODBUS_ANALOG_IN1    			;		// 0	1	Analog input 1 range. 
	//int	MODBUS_ANALOG_IN2 				;		// 0	0	Analog input 2 range.  RESERVED FOR FUTURE USE
	//int	MODBUS_DIGITAL_IN1 				;		// 0	2	Digital occupied mode trigger 
	//int	MODBUS_OUTPUT1_DELAY_OFF_TO_ON  ;		// 0	255	OFF to ON delay time (sec)
	//int	MODBUS_OUTPUT2_DELAY_OFF_TO_ON  ;		// 0	255	OFF to ON delay time (sec)
	//int	MODBUS_OUTPUT3_DELAY_OFF_TO_ON  ;		// 0	255	OFF to ON delay time (sec)
	//int	MODBUS_OUTPUT4_DELAY_OFF_TO_ON  ;		// 0	255	OFF to ON delay time (sec)
	//int	MODBUS_OUTPUT5_DELAY_OFF_TO_ON  ;		// 0	255	OFF to ON delay time (sec)
	//int	MODBUS_OUTPUT1_DELAY_ON_TO_OFF   ;		// 0	255	ON to OFF delay time (sec)
	//int	MODBUS_OUTPUT2_DELAY_ON_TO_OFF  	;	// 0	255	ON to OFF delay time (sec)
	//int	MODBUS_OUTPUT3_DELAY_ON_TO_OFF  ;		// 0	255	ON to OFF delay time (sec)
	//int	MODBUS_OUTPUT4_DELAY_ON_TO_OFF  ;		// 0	255	ON to OFF delay time (sec)
	//int	MODBUS_OUTPUT5_DELAY_ON_TO_OFF  ;		// 0	255	ON to OFF delay time (sec)
	//int	MODBUS_CYCLING_DELAY  			;		// 0	20	Delay between going out of heating or cooling and then back in. (1 min)      			
	//int	MODBUS_CHANGOVER_DELAY 			;		// 0	200	Delay between going from cooling to heating or vice versa (1 min)
	//int	MODBUS_DISPLAY 					;		// 0	1	Display setting.  0 = temperature  1 = setpoint
	//int	MODBUS_LED1_CONTROL 			;		// 0	22	Determines what controls the state of the LED
	//int	MODBUS_LED2_CONTROL 			;		// 0	22	Determines what controls the state of the LED
	//int	MODBUS_LED3_CONTROL 			;		// 0	22	Determines what controls the state of the LED
	//int	MODBUS_LED4_CONTROL 			;		// 0	22	Determines what controls the state of the LED
	//int	MODBUS_LED5_CONTROL 			;		// 0	22	Determines what controls the state of the LED
	//int	MODBUS_LED6_CONTROL 			;		// 0	22	Determines what controls the state of the LED
	//int	MODBUS_LED7_CONTROL 			;		// 0	22	Determines what controls the state of the LED
	//int	MODBUS_OVERRIDE_TIMER 			;// 0	255	Determines what controls the state of the LED
	//int	MODBUS_OVERRIDE_TIMER_LEFT;



	//	int MODBUS_FILTER;
	//	int MODBUS_HEAT_COOL_CONFIG;
	//	int MODBUS_INTERNAL_TEMP_IC;
	//	int MODBUS_INTERNAL_THERMISTOR;
	//	int MODBUS_CALIBRATION_INTERNAL_THERMISTOR;
	//	int MODBUS_CALIBRATION_ANALOG_IN2;
	//	int MODBUS_TABLE1_ZERO;                     // 1     254    the range from reg 20 to reg 41.A changable look up table for "custom" sensor 
	//	int MODBUS_TABLE1_HALFONE;                  //              the range of input voltage is 0----5v and the range is divided 10 equal partions;at 0.5v interval
	//	int MODBUS_TABLE1_ONE;                      //              the value's unit in the table is different according to different sensor
	//	int MODBUS_TABLE1_HALFTWO;                 
	//	int MODBUS_TABLE1_TWO;
	//	int MODBUS_TABLE1_HALFTHREE;
	//	int MODBUS_TABLE1_THREE;
	//	int MODBUS_TABLE1_HALFFOUR;
	//	int MODBUS_TABLE1_FOUR;
	//	int MODBUS_TABLE1_HALFFIVE;
	//	int MODBUS_TABLE1_FIVE;
	//	int MODBUS_TABLE2_ZERO;
	//	int MODBUS_TABLE2_HALFONE;
	//	int MODBUS_TABLE2_ONE;
	//	int MODBUS_TABLE2_HALFTWO;
	//	int MODBUS_TABLE2_TWO;
	//	int MODBUS_TABLE2_HALFTHREE;
	//	int MODBUS_TABLE2_THREE;
	//	int MODBUS_TABLE2_HALFFOUR;
	//	int MODBUS_TABLE2_FOUR;
	//	int MODBUS_TABLE2_HALFFIVE;
	//	int MODBUS_TABLE2_FIVE ;
	//	int MODBUS_INPUT1_SELECT  ;                        //1    254 reg 241 select which way the analog input is
	//	int MODBUS_UNIVERSAL_DB_HI ;
	//	int MODBUS_UNIVERSAL_DB_LO ;
	//	int MODBUS_UNIVERSAL_PTERM ;                       //1    254 reg 244 is the address of P term a universal PID
	//	int MODBUS_UNIVERSAL_ITERM ;                       //1    254 reg 245 is the address of I term a universal PID
	//	int MODBUS_UNIVERSAL_SET ;                         //1    254 reg 246 is the setpoint for universal PID 
	//	int MODBUS_PID_OUTPUT1 ;                           //1    254 reg 247 select which type PID to be caculate for control output
	//	int MODBUS_PID_OUTPUT2 ;   
	//	int MODBUS_PID_OUTPUT3 ;   
	//	int MODBUS_PID_OUTPUT4 ;   
	//	int MODBUS_PID_OUTPUT5 ;   
	//	int MODBUS_PID_OUTPUT6 ;   
	//	int MODBUS_PID_OUTPUT7 ;
	//	int MODBUS_UNIVERSAL_OUTPUT_BEGIN ; //    254 control OUTPUT;there are 7 status
	//	int MODBUS_UNIVERSAL_OUTPUT_COOL1 ;
	//	int MODBUS_UNIVERSAL_OUTPUT_COOL2 ;
	//	int MODBUS_UNIVERSAL_OUTPUT_COOL3 ;
	//	int MODBUS_UNIVERSAL_OUTPUT_HEAT1 ; //    258  
	//	int MODBUS_UNIVERSAL_OUTPUT_HEAT2 ;
	//	int MODBUS_UNIVERSAL_OUTPUT_HEAT3 ;
	//	int MODBUS_UNIVERSAL_VALVE_BEGIN ; //261     control the status of valve
	//	int MODBUS_UNIVERSAL_VALVE_COOL1 ;
	//	int MODBUS_UNIVERSAL_VALVE_COOL2 ;
	//	int MODBUS_UNIVERSAL_VALVE_COOL3 ;
	//	int MODBUS_UNIVERSAL_VALVE_HEAT1 ;
	//	int MODBUS_UNIVERSAL_VALVE_HEAT2 ;
	//	int MODBUS_UNIVERSAL_VALVE_HEAT3 ;
	//	int MODBUS_HEAT_UNIVERSAL_TABLE	 ;
	//	int MODBUS_COOL_UNIVERSAL_TABLE  ;              //     269  
	//	int MODBUS_PID_UNIVERSAL ;                      //     270  
	//	int MODBUS_UNITS1_HIGH ;                        //     271
	//	int MODBUS_UNITS1_LOW  ;                        //     272
	//	int MODBUS_UNITS2_HIGH ;                        //     273
	//	int MODBUS_UNITS2_LOW ;                         //     274
	//	int MODBUS_UNIVERSAL_NIGHTSET ;                 //     275
	//	int MODBUS_HEAT_ORIGINAL_TABLE ;                //     276       
	//	int MODBUS_COOL_ORIGINAL_TABLE ;                //     277
	//	int MODBUS_PID2_MODE_OPERATION;
	//	int MODBUS_VALVE_TRAVEL_TIME ;
	//	int MODBUS_MODE_OUTPUT1;
	//	int MODBUS_MODE_OUTPUT2;
	//	int MODBUS_MODE_OUTPUT3;
	//	int MODBUS_MODE_OUTPUT4;						//     	283
	//	int MODBUS_MODE_OUTPUT5;						//	   	284	
	//	int MODBUS_VALVE_PERCENT;						//	   	285
	//	int MODBUS_INTERLOCK_OUTPUT1;					//		286
	//	int MODBUS_INTERLOCK_OUTPUT2;					//		287
	//	int MODBUS_INTERLOCK_OUTPUT3;
	//	int MODBUS_INTERLOCK_OUTPUT4;					//		289
	//	int MODBUS_INTERLOCK_OUTPUT5;
	//	int MODBUS_INTERLOCK_OUTPUT6;					//		291
	//	int MODBUS_INTERLOCK_OUTPUT7;					//		292
	//	int MODBUS_SETPOINT_INCREASE;					//		293
	//	int MODBUS_LAST_KEY_TIMER;						//		294
	//	int MODBUS_FREEZE_TEMP_SETPOINT;				//		295
	//	int MODBUS_FREEZE_DELAY_ON;						//		296
	//	int MODBUS_FREEZE_DELAY_OFF;					//		297
	//	int MODBUS_ANALOG1_FUNCTION;					//		298
	//	int MODBUS_ANALOG2_FUNCTION;					//		299
	//	int MODBUS_DIGITAL1_FUNCTION;					//		300
	//	int MODBUS_TIMER_ON;							//		301
	//	int MODBUS_TIMER_OFF;							//		302
	//	int MODBUS_TIMER_UNITS;							//		303
	//	int MODBUS_KEYPAD_VALUE;						//		304
	//	int MODBUS_DISPLAY_HUNDRED;						//		305
	//	int MODBUS_DISPLAY_TEN;							//		306
	//	int MODBUS_DISPLAY_DIGITAL;						//		307
	//	int MODBUS_DISPLAY_STATUS;						//		308
	//	int MODBUS_INPUT_MANU_ENABLE;					//		309
	//	int MODBUS_OUTPUT_MANU_ENABLE;					//		310
	//	int MODBUS_DIGITAL_INPUT;						//		311
	//	int MODBUS_DEADMASTER_AUTO_MANUAL;              //      312  REV 35_0  // DEADMASTER_AUTO_MANUAL = 1; the output will be trigger to "AUTO" mode	 // DEADMASTER_AUTO_MANUAL = 0; the default; outputs will not change; stay in whatever mode they were last commanded  //DEADMASTER_AUTO_MANUAL = 2; the outputs will go to manual on or off as defined in register 313.
	//	int MODBUS_DEADMASTER_OUTPUT_STATE;             //      313  REV 35_0   (relay1-5) deadmaster config value during deadmaster be triggered
	//	int MODBUS_DEADMASTER_COOL_OUTPUT;              //      314  REV 35_0   (analog output - cooling)deadmaster config value during deadmaster be triggered
	//	int MODBUS_DEADMASTER_HEAT_OUTPUT;              //      315  REV 35_0   (analog output - heating)deadmaster config value during deadmaster be triggered
	//	int MODBUS_DEBUGTIMER;                          //      316		
	//	int MODBUS_DEAD_MASTER ;				   		//		317
	//	int MODBUS_ROUND_DISPLAY;						//		318
	//	int MODBUS_MIN_ADDRESS ;						//		319	// The ID of tstat should be in the range MIN and MAX address
	//	int MODBUS_MAX_ADDRESS;							//		320 
	//	int MODBUS_FAN_GRIDPOINT;						//		321
	//	int MODBUS_MODE_GRIDPOINT;						//		322
	//	int MODBUS_HOLD_GRIDPOINT;						//		323
	//	int MODBUS_CONFIGURATION;						//		324
	//	int MODBUS_UTIL_MODE;							//		325
	//	int MODBUS_EEPROM_SIZE;							//		326
	//	int MODBUS_TIMER_SELECT;						//		327	  //
	//	int MODBUS_OUTPUT1_FUNCTION;					//		328		 
	//	int MODBUS_ROTATION_OUT2;						//		329 	 
	//	int MODBUS_ROTATION_OUT3;						//		330		 
	//	int MODBUS_ROTATION_OUT4;						//		331		 
	//	int MODBUS_ROTATION_OUT5;						//		332		 
	//	int MODBUS_ROTATION_TIME_LEFT;					//		333	
	//	int MODBUS_OUTPUT2_FUNCTION;			    	//		334
	//	int MODBUS_OUTPUT3_FUNCTION;					//		335		
	//	int MODBUS_OUTPUT4_FUNCTION;					//		336	
	//	int MODBUS_OUTPUT5_FUNCTION;					//		337	
	//	int MODBUS_DEFAULT_SETPOINT;					//		338
	//	int MODBUS_SETPOINT_CONTROL;					//		339	 
	//	int MODBUS_PIR_STAGE;							//		340	  
	//	int MODBUS_OUTPUT_PWM_AUTO_COAST;			    //		341
	//	int MODBUS_OUTPUT_PWM_AUTO_COOL1;			    //		342
	//	int MODBUS_OUTPUT_PWM_AUTO_COOL2;			    //		343
	//	int MODBUS_OUTPUT_PWM_AUTO_COOL3;			    //		344
	//	int MODBUS_OUTPUT_PWM_AUTO_HEAT1;			    //		345
	//	int MODBUS_OUTPUT_PWM_AUTO_HEAT2;			    //		346
	//	int MODBUS_OUTPUT_PWM_AUTO_HEAT3;			    //		347
	//	int MODBUS_PWM_OUT4;
	//	int MODBUS_PWM_OUT5;
	//	int MODBUS_FREE_COOL_CONFIG;//bit0;free cool enable/disable;0 = disable;1= enable.	//bit1;free cool available decided by local or external master.0 =  local;1 = NC.//bit2;free cool available status;0 = not available;1= available.//bit4;show the status if NC is OK when the free cool decided by NC.				
	//	int MODBUS_VALVE_OFF_TABLE_COAST;				//		351 OFF table for analog output;
	//	int MODBUS_VALVE_OFF_TABLE_COOL1;
	//	int MODBUS_VALVE_OFF_TABLE_COOL2;
	//	int MODBUS_VALVE_OFF_TABLE_COOL3;
	//	int MODBUS_VALVE_OFF_TABLE_HEAT1;
	//	int MODBUS_VALVE_OFF_TABLE_HEAT2;
	//	int MODBUS_VALVE_OFF_TABLE_HEAT3;				//		357  
	//	int MODBUS_LOCK_REGISTER;						//		358	All registers except fan speed and manual input are not writable.0 = lock;1 = no lock.
	//	int MODBUS_FREE_COOL_OUT_TEMP;					//		359	Outside temperature for free cooling;from external sensor or NC.
	//	int MODBUS_NC_MASTER_TIME;						//		360 If outside temp be set from NC.The communication with NC must be set in this time;otherwise will set error status and use external sensor.
	//	int MODBUS_FREE_COOL_HYSTERISIS;					//		361 If the outside air temp is lower than the room temeprature by this amount; then the free cooling is worthwhile; 350 bit2 = 1;If the OAT is greater than the room temp; then free cooling mode is not worhtwhile.  350 bit2 = 0
	//	int MODBUS_OUTPUT_FREE_COOL_COAST;				//		362 Output table in free cooling mode;0 = 0%; 1 = 1-00%;2 = MIN->100%;3 = MIN|100%;4 = MIN
	//	int MODBUS_OUTPUT_FREE_COOL_COOL1;
	//	int MODBUS_OUTPUT_FREE_COOL_COOL2;
	//	int MODBUS_OUTPUT_FREE_COOL_COOL3;
	//	int MODBUS_OUTPUT_FREE_COOL_HEAT1;
	//	int MODBUS_OUTPUT_FREE_COOL_HEAT2;
	//	int MODBUS_OUTPUT_FREE_COOL_HEAT3; 				//		368
	//	int MODBUS_MIN_AIR;								//		369 The minimum output for free cooling  
	//	int MODBUS_OAT_HOTTEST;							//		370 Outside air temperature in hottest day
	//	int MODBUS_OAT_COLDEST;							//		371 Outside air temperature in coldest day
	//	int MODBUS_OFFSET_HOTTEST;						//		372 Offset in hottest day
	//	int MODBUS_OFFSET_COLDEST;						//		373 Offset in codest day
	//	int MODBUS_TWO_BYTE_SETPOINT;					//		374 Store setpoint in two bytes ;the resolution is 0.1
	//	int MODBUS_CURRENT_SETPOINT;					//		375 Current setpoint  = user setpoint  + offset setpoint
	//	int MODBUS_SETPOINT_OFFSET;						//		376 Setpoint offset
	//	int MODBUS_CHANGEOVER_SENSOR_MODE;				//		377	Change over sensor mode;1 = cooling mode;0 = heating mode.
	//	int MODBUS_EXTERNAL_SENSOR_INUSE;				//		378 External temp sensor if in use;0 = not use;1 = in use
	//	int MODBUS_EXTERNAL_SENSOR_STATUS;				//		379	Status shows if external sensor is opening or short circut;0 = OK;1 = FAIL
	//	int MODBUS_NEW_COOLING_SETPOINT;				//		380 135- COOLING SETPOINT
	//	int MODBUS_DAYSETPOINT_OPTION;					//		381
	//	int MODBUS_DELAY1_ON_TO_OFF_TIME_CURRENT;	    //		382 Timer left for output1 ON to OFF delay
	//	int MODBUS_DELAY2_ON_TO_OFF_TIME_CURRENT;		//		383 Timer left for output2 ON to OFF delay
	//	int MODBUS_DELAY3_ON_TO_OFF_TIME_CURRENT;		//		384 Timer left for output3 ON to OFF delay
	//	int MODBUS_DELAY4_ON_TO_OFF_TIME_CURRENT;		//		385 Timer left for output4 ON to OFF delay
	//	int MODBUS_DELAY5_ON_TO_OFF_TIME_CURRENT;		//		386 Timer left for output5 ON to OFF delay
	//	int MODBUS_DELAY1_OFF_TO_ON_TIME_CURRENT;		//		387 Timer left for output1 OFF to ON delay
	//	int MODBUS_DELAY2_OFF_TO_ON_TIME_CURRENT;		//		388 Timer left for output2 OFF to ON delay
	//	int MODBUS_DELAY3_OFF_TO_ON_TIME_CURRENT;		//		389 Timer left for output3 OFF to ON delay
	//	int MODBUS_DELAY4_OFF_TO_ON_TIME_CURRENT;		//		390 Timer left for output4 OFF to ON delay
	//	int MODBUS_DELAY5_OFF_TO_ON_TIME_CURRENT;		//		391 Timer left for output5 OFF to ON delay
	//	int MODBUS_WINDOW_INTERLOCK_DELAY;
	//	int MODBUS_UNIVERSAL_OFF_OUTPUT_BEGIN ; //393     control OUTPUT_1TO5;there are 7 status
	//	int MODBUS_UNIVERSAL_OFF_OUTPUT_COOL1 ;
	//	int MODBUS_UNIVERSAL_OFF_OUTPUT_COOL2 ;
	//	int MODBUS_UNIVERSAL_OFF_OUTPUT_COOL3 ;
	//	int MODBUS_UNIVERSAL_OFF_OUTPUT_HEAT1 ; ////     
	//	int MODBUS_UNIVERSAL_OFF_OUTPUT_HEAT2 ;
	//	int MODBUS_UNIVERSAL_OFF_OUTPUT_HEAT3 ;	
	//	int MODBUS_UNIVERSAL_OFF_VALVE_BEGIN ; //400     control the status of valve
	//	int MODBUS_UNIVERSAL_OFF_VALVE_COOL1 ;
	//	int MODBUS_UNIVERSAL_OFF_VALVE_COOL2 ;
	//	int MODBUS_UNIVERSAL_OFF_VALVE_COOL3 ;
	//	int MODBUS_UNIVERSAL_OFF_VALVE_HEAT1 ;
	//	int MODBUS_UNIVERSAL_OFF_VALVE_HEAT2 ;
	//	int MODBUS_UNIVERSAL_OFF_VALVE_HEAT3 ;
	//	int MODBUS_DURA_WINTER_SUMMER;//407
	//	int MODBUS_FREE_COOL_SETPOINT;
	//	int MODBUS_FREE_COOL_MAX_SETPOINT;
	//	int MODBUS_FREE_COOL_MIN_SETPOINT;
	//	int MODBUS_FREE_COOL_MIN_DAMPER;
	//	int MODBUS_TEST1 ;//	
	//	int MODBUS_TEST2 ;
	//	int MODBUS_TEST3 ;
	//	int MODBUS_TEST4;


};
int _Get(wchar_t *str,int Mdb_Adress_Map=1);
//int _Get(wchar_t *str);
float my_get_tstat_version(unsigned short tstat_id);
float my_get_curtstat_version();
bool my_get_serialnumber(long & serial,int the_id_of_product);
 UINT my_get_serialnumber();

 void Savetmp_Mdb_Adress_Map();
 void Set_Mdb_Adress_Map(int myMdb_Adress_Map);
 void Restore_Mdb_Adress_Map();
  BOOL DelDirW(CString strSrcPath);

