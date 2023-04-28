/*
 * DIO_config.h
 *
 *  Created on: Apr 25, 2023
 *      Author: Sherif Ahmed
 */

#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_
/*step5.determine configuration ports and pins input or output */
/**you can use INPUT or OUTPUT for direction**/

#define PA_PIN0_DIR        	OUTPUT
#define PA_PIN1_DIR        	OUTPUT
#define PA_PIN2_DIR         OUTPUT
#define PA_PIN3_DIR         OUTPUT
#define PA_PIN4_DIR			OUTPUT
#define PA_PIN5_DIR			OUTPUT
#define PA_PIN6_DIR			OUTPUT
#define PA_PIN7_DIR			OUTPUT
/*10010110*/

#define PB_PIN0_DIR        	INPUT
#define PB_PIN1_DIR        	OUTPUT
#define PB_PIN2_DIR         OUTPUT
#define PB_PIN3_DIR         INPUT
#define PB_PIN4_DIR         OUTPUT
#define PB_PIN5_DIR         INPUT
#define PB_PIN6_DIR         INPUT
#define PB_PIN7_DIR         OUTPUT

#define PC_PIN0_DIR        	OUTPUT
#define PC_PIN1_DIR        	OUTPUT
#define PC_PIN2_DIR         OUTPUT
#define PC_PIN3_DIR         OUTPUT
#define PC_PIN4_DIR         OUTPUT
#define PC_PIN5_DIR         OUTPUT
#define PC_PIN6_DIR         OUTPUT
#define PC_PIN7_DIR         OUTPUT

#define PD_PIN0_DIR        	OUTPUT
#define PD_PIN1_DIR        	OUTPUT
#define PD_PIN2_DIR         OUTPUT
#define PD_PIN3_DIR         OUTPUT
#define PD_PIN4_DIR         OUTPUT
#define PD_PIN5_DIR         OUTPUT
#define PD_PIN6_DIR         OUTPUT
#define PD_PIN7_DIR         OUTPUT
                  /***********for value**********/
#define PA_PIN0_VAL        	LOW   // as it's defined INPUT direction above so either float or pull-up
#define PA_PIN1_VAL        	LOW   // as it's defined OUTPUT direction above so either HIGH or LOW
#define PA_PIN2_VAL         LOW
#define PA_PIN3_VAL         LOW
#define PA_PIN4_VAL         LOW
#define PA_PIN5_VAL         LOW
#define PA_PIN6_VAL         LOW
#define PA_PIN7_VAL         LOW

#define PB_PIN0_VAL        	FLOAT  // as it's defined INPUT direction above so either float or pull-up
#define PB_PIN1_VAL        	HIGH   // as it's defined OUTPUT direction above so either HIGH or LOW
#define PB_PIN2_VAL         LOW
#define PB_PIN3_VAL         PULLUP
#define PB_PIN4_VAL         HIGH
#define PB_PIN5_VAL         FLOAT
#define PB_PIN6_VAL         PULLUP
#define PB_PIN7_VAL         LOW

#define PC_PIN0_VAL        	FLOAT  // as it's defined INPUT direction above so either float or pull-up
#define PC_PIN1_VAL        	HIGH   // as it's defined OUTPUT direction above so either HIGH or LOW
#define PC_PIN2_VAL         LOW
#define PC_PIN3_VAL         PULLUP
#define PC_PIN4_VAL         HIGH
#define PC_PIN5_VAL         FLOAT
#define PC_PIN6_VAL         PULLUP
#define PC_PIN7_VAL         LOW

#define PD_PIN0_VAL        	FLOAT  // as it's defined INPUT direction above so either float or pull-up
#define PD_PIN1_VAL        	HIGH   // as it's defined OUTPUT direction above so either HIGH or LOW
#define PD_PIN2_VAL         LOW
#define PD_PIN3_VAL         PULLUP
#define PD_PIN4_VAL         HIGH
#define PD_PIN5_VAL         FLOAT
#define PD_PIN6_VAL         PULLUP
#define PD_PIN7_VAL         LOW

#endif /* DIO_CONFIG_H_ */
