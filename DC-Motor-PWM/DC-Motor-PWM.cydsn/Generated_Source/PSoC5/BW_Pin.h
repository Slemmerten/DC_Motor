/*******************************************************************************
* File Name: BW_Pin.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_BW_Pin_H) /* Pins BW_Pin_H */
#define CY_PINS_BW_Pin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BW_Pin_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 BW_Pin__PORT == 15 && ((BW_Pin__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    BW_Pin_Write(uint8 value);
void    BW_Pin_SetDriveMode(uint8 mode);
uint8   BW_Pin_ReadDataReg(void);
uint8   BW_Pin_Read(void);
void    BW_Pin_SetInterruptMode(uint16 position, uint16 mode);
uint8   BW_Pin_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the BW_Pin_SetDriveMode() function.
     *  @{
     */
        #define BW_Pin_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define BW_Pin_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define BW_Pin_DM_RES_UP          PIN_DM_RES_UP
        #define BW_Pin_DM_RES_DWN         PIN_DM_RES_DWN
        #define BW_Pin_DM_OD_LO           PIN_DM_OD_LO
        #define BW_Pin_DM_OD_HI           PIN_DM_OD_HI
        #define BW_Pin_DM_STRONG          PIN_DM_STRONG
        #define BW_Pin_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define BW_Pin_MASK               BW_Pin__MASK
#define BW_Pin_SHIFT              BW_Pin__SHIFT
#define BW_Pin_WIDTH              1u

/* Interrupt constants */
#if defined(BW_Pin__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BW_Pin_SetInterruptMode() function.
     *  @{
     */
        #define BW_Pin_INTR_NONE      (uint16)(0x0000u)
        #define BW_Pin_INTR_RISING    (uint16)(0x0001u)
        #define BW_Pin_INTR_FALLING   (uint16)(0x0002u)
        #define BW_Pin_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define BW_Pin_INTR_MASK      (0x01u) 
#endif /* (BW_Pin__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BW_Pin_PS                     (* (reg8 *) BW_Pin__PS)
/* Data Register */
#define BW_Pin_DR                     (* (reg8 *) BW_Pin__DR)
/* Port Number */
#define BW_Pin_PRT_NUM                (* (reg8 *) BW_Pin__PRT) 
/* Connect to Analog Globals */                                                  
#define BW_Pin_AG                     (* (reg8 *) BW_Pin__AG)                       
/* Analog MUX bux enable */
#define BW_Pin_AMUX                   (* (reg8 *) BW_Pin__AMUX) 
/* Bidirectional Enable */                                                        
#define BW_Pin_BIE                    (* (reg8 *) BW_Pin__BIE)
/* Bit-mask for Aliased Register Access */
#define BW_Pin_BIT_MASK               (* (reg8 *) BW_Pin__BIT_MASK)
/* Bypass Enable */
#define BW_Pin_BYP                    (* (reg8 *) BW_Pin__BYP)
/* Port wide control signals */                                                   
#define BW_Pin_CTL                    (* (reg8 *) BW_Pin__CTL)
/* Drive Modes */
#define BW_Pin_DM0                    (* (reg8 *) BW_Pin__DM0) 
#define BW_Pin_DM1                    (* (reg8 *) BW_Pin__DM1)
#define BW_Pin_DM2                    (* (reg8 *) BW_Pin__DM2) 
/* Input Buffer Disable Override */
#define BW_Pin_INP_DIS                (* (reg8 *) BW_Pin__INP_DIS)
/* LCD Common or Segment Drive */
#define BW_Pin_LCD_COM_SEG            (* (reg8 *) BW_Pin__LCD_COM_SEG)
/* Enable Segment LCD */
#define BW_Pin_LCD_EN                 (* (reg8 *) BW_Pin__LCD_EN)
/* Slew Rate Control */
#define BW_Pin_SLW                    (* (reg8 *) BW_Pin__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BW_Pin_PRTDSI__CAPS_SEL       (* (reg8 *) BW_Pin__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BW_Pin_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BW_Pin__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BW_Pin_PRTDSI__OE_SEL0        (* (reg8 *) BW_Pin__PRTDSI__OE_SEL0) 
#define BW_Pin_PRTDSI__OE_SEL1        (* (reg8 *) BW_Pin__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BW_Pin_PRTDSI__OUT_SEL0       (* (reg8 *) BW_Pin__PRTDSI__OUT_SEL0) 
#define BW_Pin_PRTDSI__OUT_SEL1       (* (reg8 *) BW_Pin__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BW_Pin_PRTDSI__SYNC_OUT       (* (reg8 *) BW_Pin__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(BW_Pin__SIO_CFG)
    #define BW_Pin_SIO_HYST_EN        (* (reg8 *) BW_Pin__SIO_HYST_EN)
    #define BW_Pin_SIO_REG_HIFREQ     (* (reg8 *) BW_Pin__SIO_REG_HIFREQ)
    #define BW_Pin_SIO_CFG            (* (reg8 *) BW_Pin__SIO_CFG)
    #define BW_Pin_SIO_DIFF           (* (reg8 *) BW_Pin__SIO_DIFF)
#endif /* (BW_Pin__SIO_CFG) */

/* Interrupt Registers */
#if defined(BW_Pin__INTSTAT)
    #define BW_Pin_INTSTAT            (* (reg8 *) BW_Pin__INTSTAT)
    #define BW_Pin_SNAP               (* (reg8 *) BW_Pin__SNAP)
    
	#define BW_Pin_0_INTTYPE_REG 		(* (reg8 *) BW_Pin__0__INTTYPE)
#endif /* (BW_Pin__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_BW_Pin_H */


/* [] END OF FILE */
