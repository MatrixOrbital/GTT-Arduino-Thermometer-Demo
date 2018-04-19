/**
 *  @file	gtt_enum.h
 *  @brief	this file contains all the enumerations used in the gtt client library
 */
#ifndef _GTT_ENUM_H
#define _GTT_ENUM_H

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

/*! enum eEventNodeType */
typedef enum eEventNodeType {
	eEventNodeType_SetValueText = 9, /*!< SetValueText */ 
	eEventNodeType_GetValueText = 10, /*!< GetValueText */ 
	eEventNodeType_Comparison = 11, /*!< Comparison */ 
	eEventNodeType_AppendValueText = 12, /*!< AppendValueText */ 
	eEventNodeType_Convert = 13, /*!< Convert */ 
	eEventNodeType_Math = 14, /*!< Math */ 
	eEventNodeType_RunClassicScript = 15, /*!< RunClassicScript */ 
	eEventNodeType_SetFocus = 16, /*!< SetFocus */ 
	eEventNodeType_SetObjectPropertyValue = 17, /*!< SetObjectPropertyValue */ 
	eEventNodeType_GetObjectPropertyValue = 18, /*!< GetObjectPropertyValue */ 
	eEventNodeType_SendEventToHost = 19, /*!< SendEventToHost */ 
} eEventNodeType;

/*! enum ePropertyType */
typedef enum ePropertyType {
	ePropertyType_Unknown = 0, /*!< Unknown */ 
	ePropertyType_U8 = 1, /*!< U8 */ 
	ePropertyType_S8 = 2, /*!< S8 */ 
	ePropertyType_U16 = 3, /*!< U16 */ 
	ePropertyType_S16 = 4, /*!< S16 */ 
	ePropertyType_U32 = 5, /*!< U32 */ 
	ePropertyType_S32 = 6, /*!< S32 */ 
	ePropertyType_FixedDec = 7, /*!< FixedDec */ 
	ePropertyType_FixedHex = 8, /*!< FixedHex */ 
	ePropertyType_ByteArrayL8 = 9, /*!< ByteArrayL8 */ 
	ePropertyType_ByteArrayL16 = 10, /*!< ByteArrayL16 */ 
	ePropertyType_WordArrayL8 = 11, /*!< WordArrayL8 */ 
	ePropertyType_SignedWordArrayL8 = 12, /*!< SignedWordArrayL8 */ 
	ePropertyType_WordArrayL32 = 13, /*!< WordArrayL32 */ 
	ePropertyType_Text = 14, /*!< Text */ 
	ePropertyType_Float = 15, /*!< Float */ 
	ePropertyType_Number = 16, /*!< Number */ 
	ePropertyType_NumberArray = 17, /*!< NumberArray */ 
} ePropertyType;

/*! enum eEventNodeSocket */
typedef enum eEventNodeSocket {
	eEventNodeSocket_event_BaseObject_OnPropertyChange_Execute = 0, /*!< event_BaseObject_OnPropertyChange_Execute */ 
	eEventNodeSocket_event_BaseObject_OnPropertyChange_EventID = 1, /*!< event_BaseObject_OnPropertyChange_EventID */ 
	eEventNodeSocket_event_BaseObject_OnPropertyChange_ObjectID = 2, /*!< event_BaseObject_OnPropertyChange_ObjectID */ 
	eEventNodeSocket_event_BaseObject_OnPropertyChange_PropertyID = 3, /*!< event_BaseObject_OnPropertyChange_PropertyID */ 
	eEventNodeSocket_event_VisualObject_OnKey_Execute = 0, /*!< event_VisualObject_OnKey_Execute */ 
	eEventNodeSocket_event_VisualObject_OnKey_EventID = 1, /*!< event_VisualObject_OnKey_EventID */ 
	eEventNodeSocket_event_VisualObject_OnKey_ObjectID = 2, /*!< event_VisualObject_OnKey_ObjectID */ 
	eEventNodeSocket_event_VisualObject_OnKey_Row = 3, /*!< event_VisualObject_OnKey_Row */ 
	eEventNodeSocket_event_VisualObject_OnKey_Col = 4, /*!< event_VisualObject_OnKey_Col */ 
	eEventNodeSocket_event_VisualObject_OnKey_ScanCode = 5, /*!< event_VisualObject_OnKey_ScanCode */ 
	eEventNodeSocket_event_VisualObject_OnKey_Down = 6, /*!< event_VisualObject_OnKey_Down */ 
	eEventNodeSocket_EventGraph_SetValueText_input_Execute = 0, /*!< EventGraph_SetValueText_input_Execute */ 
	eEventNodeSocket_EventGraph_SetValueText_input_ObjectID = 1, /*!< EventGraph_SetValueText_input_ObjectID */ 
	eEventNodeSocket_EventGraph_SetValueText_input_PropertyID = 2, /*!< EventGraph_SetValueText_input_PropertyID */ 
	eEventNodeSocket_EventGraph_SetValueText_input_Value = 3, /*!< EventGraph_SetValueText_input_Value */ 
	eEventNodeSocket_EventGraph_SetValueText_output_Execute = 0, /*!< EventGraph_SetValueText_output_Execute */ 
	eEventNodeSocket_EventGraph_GetValueText_input_Execute = 0, /*!< EventGraph_GetValueText_input_Execute */ 
	eEventNodeSocket_EventGraph_GetValueText_input_ObjectID = 1, /*!< EventGraph_GetValueText_input_ObjectID */ 
	eEventNodeSocket_EventGraph_GetValueText_input_PropertyID = 2, /*!< EventGraph_GetValueText_input_PropertyID */ 
	eEventNodeSocket_EventGraph_GetValueText_output_Execute = 0, /*!< EventGraph_GetValueText_output_Execute */ 
	eEventNodeSocket_EventGraph_GetValueText_output_Value = 1, /*!< EventGraph_GetValueText_output_Value */ 
	eEventNodeSocket_EventGraph_Comparison_input_Execute = 0, /*!< EventGraph_Comparison_input_Execute */ 
	eEventNodeSocket_EventGraph_Comparison_input_ObjectIDA = 1, /*!< EventGraph_Comparison_input_ObjectIDA */ 
	eEventNodeSocket_EventGraph_Comparison_input_PropertyIDA = 2, /*!< EventGraph_Comparison_input_PropertyIDA */ 
	eEventNodeSocket_EventGraph_Comparison_input_ObjectIDB = 3, /*!< EventGraph_Comparison_input_ObjectIDB */ 
	eEventNodeSocket_EventGraph_Comparison_input_PropertyIDB = 4, /*!< EventGraph_Comparison_input_PropertyIDB */ 
	eEventNodeSocket_EventGraph_Comparison_input_Compare = 5, /*!< EventGraph_Comparison_input_Compare */ 
	eEventNodeSocket_EventGraph_Comparison_output_Execute = 0, /*!< EventGraph_Comparison_output_Execute */ 
	eEventNodeSocket_EventGraph_Comparison_output_True = 1, /*!< EventGraph_Comparison_output_True */ 
	eEventNodeSocket_EventGraph_Comparison_output_False = 2, /*!< EventGraph_Comparison_output_False */ 
	eEventNodeSocket_EventGraph_AppendValueText_input_Execute = 0, /*!< EventGraph_AppendValueText_input_Execute */ 
	eEventNodeSocket_EventGraph_AppendValueText_input_ObjectID = 1, /*!< EventGraph_AppendValueText_input_ObjectID */ 
	eEventNodeSocket_EventGraph_AppendValueText_input_PropertyID = 2, /*!< EventGraph_AppendValueText_input_PropertyID */ 
	eEventNodeSocket_EventGraph_AppendValueText_input_Value = 3, /*!< EventGraph_AppendValueText_input_Value */ 
	eEventNodeSocket_EventGraph_AppendValueText_output_Execute = 0, /*!< EventGraph_AppendValueText_output_Execute */ 
	eEventNodeSocket_EventGraph_Convert_input_Execute = 0, /*!< EventGraph_Convert_input_Execute */ 
	eEventNodeSocket_EventGraph_Convert_input_InputU16 = 1, /*!< EventGraph_Convert_input_InputU16 */ 
	eEventNodeSocket_EventGraph_Convert_input_InputS16 = 2, /*!< EventGraph_Convert_input_InputS16 */ 
	eEventNodeSocket_EventGraph_Convert_input_InputU8 = 3, /*!< EventGraph_Convert_input_InputU8 */ 
	eEventNodeSocket_EventGraph_Convert_input_InputFloat = 4, /*!< EventGraph_Convert_input_InputFloat */ 
	eEventNodeSocket_EventGraph_Convert_input_InputText = 5, /*!< EventGraph_Convert_input_InputText */ 
	eEventNodeSocket_EventGraph_Convert_input_From = 6, /*!< EventGraph_Convert_input_From */ 
	eEventNodeSocket_EventGraph_Convert_input_To = 7, /*!< EventGraph_Convert_input_To */ 
	eEventNodeSocket_EventGraph_Convert_output_Execute = 0, /*!< EventGraph_Convert_output_Execute */ 
	eEventNodeSocket_EventGraph_Convert_output_OutputU16 = 1, /*!< EventGraph_Convert_output_OutputU16 */ 
	eEventNodeSocket_EventGraph_Convert_output_OutputS16 = 2, /*!< EventGraph_Convert_output_OutputS16 */ 
	eEventNodeSocket_EventGraph_Convert_output_OutputU8 = 3, /*!< EventGraph_Convert_output_OutputU8 */ 
	eEventNodeSocket_EventGraph_Convert_output_OutputFloat = 4, /*!< EventGraph_Convert_output_OutputFloat */ 
	eEventNodeSocket_EventGraph_Convert_output_OutputText = 5, /*!< EventGraph_Convert_output_OutputText */ 
	eEventNodeSocket_EventGraph_Math_input_Execute = 0, /*!< EventGraph_Math_input_Execute */ 
	eEventNodeSocket_EventGraph_Math_input_Operation = 1, /*!< EventGraph_Math_input_Operation */ 
	eEventNodeSocket_EventGraph_Math_input_Input1 = 2, /*!< EventGraph_Math_input_Input1 */ 
	eEventNodeSocket_EventGraph_Math_input_Input2 = 3, /*!< EventGraph_Math_input_Input2 */ 
	eEventNodeSocket_EventGraph_Math_output_Execute = 0, /*!< EventGraph_Math_output_Execute */ 
	eEventNodeSocket_EventGraph_Math_output_Output = 1, /*!< EventGraph_Math_output_Output */ 
	eEventNodeSocket_EventGraph_RunClassicScript_input_Execute = 0, /*!< EventGraph_RunClassicScript_input_Execute */ 
	eEventNodeSocket_EventGraph_RunClassicScript_input_ScriptName = 1, /*!< EventGraph_RunClassicScript_input_ScriptName */ 
	eEventNodeSocket_EventGraph_RunClassicScript_output_Execute = 0, /*!< EventGraph_RunClassicScript_output_Execute */ 
	eEventNodeSocket_EventGraph_SetFocus_input_Execute = 0, /*!< EventGraph_SetFocus_input_Execute */ 
	eEventNodeSocket_EventGraph_SetFocus_input_ObjectID = 1, /*!< EventGraph_SetFocus_input_ObjectID */ 
	eEventNodeSocket_EventGraph_SetFocus_output_Execute = 0, /*!< EventGraph_SetFocus_output_Execute */ 
	eEventNodeSocket_EventGraph_SetObjectPropertyValue_input_Execute = 0, /*!< EventGraph_SetObjectPropertyValue_input_Execute */ 
	eEventNodeSocket_EventGraph_SetObjectPropertyValue_input_ObjectID = 1, /*!< EventGraph_SetObjectPropertyValue_input_ObjectID */ 
	eEventNodeSocket_EventGraph_SetObjectPropertyValue_input_PropertyID = 2, /*!< EventGraph_SetObjectPropertyValue_input_PropertyID */ 
	eEventNodeSocket_EventGraph_SetObjectPropertyValue_input_Value = 3, /*!< EventGraph_SetObjectPropertyValue_input_Value */ 
	eEventNodeSocket_EventGraph_SetObjectPropertyValue_output_Execute = 0, /*!< EventGraph_SetObjectPropertyValue_output_Execute */ 
	eEventNodeSocket_EventGraph_GetObjectPropertyValue_input_Execute = 0, /*!< EventGraph_GetObjectPropertyValue_input_Execute */ 
	eEventNodeSocket_EventGraph_GetObjectPropertyValue_input_ObjectID = 1, /*!< EventGraph_GetObjectPropertyValue_input_ObjectID */ 
	eEventNodeSocket_EventGraph_GetObjectPropertyValue_input_PropertyID = 2, /*!< EventGraph_GetObjectPropertyValue_input_PropertyID */ 
	eEventNodeSocket_EventGraph_GetObjectPropertyValue_output_Execute = 0, /*!< EventGraph_GetObjectPropertyValue_output_Execute */ 
	eEventNodeSocket_EventGraph_GetObjectPropertyValue_output_Value = 1, /*!< EventGraph_GetObjectPropertyValue_output_Value */ 
	eEventNodeSocket_EventGraph_SendEventToHost_input_Execute = 0, /*!< EventGraph_SendEventToHost_input_Execute */ 
	eEventNodeSocket_EventGraph_SendEventToHost_output_Execute = 0, /*!< EventGraph_SendEventToHost_output_Execute */ 
	eEventNodeSocket_event_Button_Click_Execute = 0, /*!< event_Button_Click_Execute */ 
	eEventNodeSocket_event_Button_Click_EventID = 1, /*!< event_Button_Click_EventID */ 
	eEventNodeSocket_event_Button_Click_ObjectID = 2, /*!< event_Button_Click_ObjectID */ 
	eEventNodeSocket_event_Button_Click_State = 3, /*!< event_Button_Click_State */ 
} eEventNodeSocket;

/*! enum eEventID */
typedef enum eEventID {
	eEventID_BaseObject_OnPropertyChange = 257, /*!< BaseObject_OnPropertyChange */ 
	eEventID_VisualObject_OnKey = 512, /*!< VisualObject_OnKey */ 
	eEventID_Button_Click = 5376, /*!< Button_Click */ 
} eEventID;

/*! enum eObjectType */
typedef enum eObjectType {
	eObjectType_Unknown = 0, /*!< Unknown */ 
	eObjectType_BaseObject = 1, /*!< BaseObject */ 
	eObjectType_VisualObject = 2, /*!< VisualObject */ 
	eObjectType_Gauge = 3, /*!< Gauge */ 
	eObjectType_StrokePad = 4, /*!< StrokePad */ 
	eObjectType_StoryBoard = 5, /*!< StoryBoard */ 
	eObjectType_Rectangle = 6, /*!< Rectangle */ 
	eObjectType_Trigger = 7, /*!< Trigger */ 
	eObjectType_Condition = 8, /*!< Condition */ 
	eObjectType_Label = 9, /*!< Label */ 
	eObjectType_Slider = 10, /*!< Slider */ 
	eObjectType_DataBinding = 11, /*!< DataBinding */ 
	eObjectType_NineSlice = 12, /*!< NineSlice */ 
	eObjectType_Bitmap = 13, /*!< Bitmap */ 
	eObjectType_Font = 14, /*!< Font */ 
	eObjectType_FileSystem = 15, /*!< FileSystem */ 
	eObjectType_TraceBinding = 16, /*!< TraceBinding */ 
	eObjectType_Button = 21, /*!< Button */ 
	eObjectType_GTTModule = 24, /*!< GTTModule */ 
	eObjectType_ObjectList = 26, /*!< ObjectList */ 
	eObjectType_VisualBitmap = 31, /*!< VisualBitmap */ 
	eObjectType_Animation = 32, /*!< Animation */ 
	eObjectType_EventGraph = 66, /*!< EventGraph */ 
} eObjectType;

/*! enum ePropertyID */
typedef enum ePropertyID {
	ePropertyID_BaseObject_Protected = 256, /*!< BaseObject_Protected */ 
	ePropertyID_VisualObject_Invalidated = 512, /*!< VisualObject_Invalidated */ 
	ePropertyID_VisualObject_Left = 513, /*!< VisualObject_Left */ 
	ePropertyID_VisualObject_Top = 514, /*!< VisualObject_Top */ 
	ePropertyID_VisualObject_Width = 515, /*!< VisualObject_Width */ 
	ePropertyID_VisualObject_Height = 516, /*!< VisualObject_Height */ 
	ePropertyID_VisualObject_CanFocus = 517, /*!< VisualObject_CanFocus */ 
	ePropertyID_VisualObject_HasFocus = 518, /*!< VisualObject_HasFocus */ 
	ePropertyID_VisualObject_Enabled = 519, /*!< VisualObject_Enabled */ 
	ePropertyID_Gauge_MinValue = 768, /*!< Gauge_MinValue */ 
	ePropertyID_Gauge_MaxValue = 769, /*!< Gauge_MaxValue */ 
	ePropertyID_Gauge_Value = 770, /*!< Gauge_Value */ 
	ePropertyID_Gauge_StartAngle = 771, /*!< Gauge_StartAngle */ 
	ePropertyID_Gauge_EndAngle = 772, /*!< Gauge_EndAngle */ 
	ePropertyID_Gauge_NeedleColorR = 773, /*!< Gauge_NeedleColorR */ 
	ePropertyID_Gauge_NeedleColorG = 774, /*!< Gauge_NeedleColorG */ 
	ePropertyID_Gauge_NeedleColorB = 775, /*!< Gauge_NeedleColorB */ 
	ePropertyID_Gauge_BackgroundR = 776, /*!< Gauge_BackgroundR */ 
	ePropertyID_Gauge_BackgroundG = 777, /*!< Gauge_BackgroundG */ 
	ePropertyID_Gauge_BackgroundB = 778, /*!< Gauge_BackgroundB */ 
	ePropertyID_Gauge_NeedleWidth = 779, /*!< Gauge_NeedleWidth */ 
	ePropertyID_Gauge_BackgroundImage = 780, /*!< Gauge_BackgroundImage */ 
	ePropertyID_Gauge_AnimationSpeed = 781, /*!< Gauge_AnimationSpeed */ 
	ePropertyID_Gauge_BaseRadius = 782, /*!< Gauge_BaseRadius */ 
	ePropertyID_Gauge_LabelFontObject = 783, /*!< Gauge_LabelFontObject */ 
	ePropertyID_Gauge_LabelR = 784, /*!< Gauge_LabelR */ 
	ePropertyID_Gauge_LabelG = 785, /*!< Gauge_LabelG */ 
	ePropertyID_Gauge_LabelB = 786, /*!< Gauge_LabelB */ 
	ePropertyID_Gauge_LabelText = 787, /*!< Gauge_LabelText */ 
	ePropertyID_Gauge_LabelLeft = 788, /*!< Gauge_LabelLeft */ 
	ePropertyID_Gauge_LabelTop = 789, /*!< Gauge_LabelTop */ 
	ePropertyID_Gauge_LabelWidth = 790, /*!< Gauge_LabelWidth */ 
	ePropertyID_Gauge_LabelHeight = 791, /*!< Gauge_LabelHeight */ 
	ePropertyID_Gauge_NeedleX = 792, /*!< Gauge_NeedleX */ 
	ePropertyID_Gauge_NeedleY = 793, /*!< Gauge_NeedleY */ 
	ePropertyID_Gauge_NeedleStartRadius = 795, /*!< Gauge_NeedleStartRadius */ 
	ePropertyID_Gauge_NeedleEndRadius = 796, /*!< Gauge_NeedleEndRadius */ 
	ePropertyID_Gauge_NeedleLocation = 797, /*!< Gauge_NeedleLocation */ 
	ePropertyID_Gauge_NeedleMode = 798, /*!< Gauge_NeedleMode */ 
	ePropertyID_Gauge_NeedleWidthTip = 799, /*!< Gauge_NeedleWidthTip */ 
	ePropertyID_Gauge_LabelFontSize = 800, /*!< Gauge_LabelFontSize */ 
	ePropertyID_StrokePad_StrokeColorR = 1024, /*!< StrokePad_StrokeColorR */ 
	ePropertyID_StrokePad_StrokeColorG = 1025, /*!< StrokePad_StrokeColorG */ 
	ePropertyID_StrokePad_StrokeColorB = 1026, /*!< StrokePad_StrokeColorB */ 
	ePropertyID_StrokePad_ColorR = 1027, /*!< StrokePad_ColorR */ 
	ePropertyID_StrokePad_ColorG = 1028, /*!< StrokePad_ColorG */ 
	ePropertyID_StrokePad_ColorB = 1029, /*!< StrokePad_ColorB */ 
	ePropertyID_StoryBoard_Duration = 1280, /*!< StoryBoard_Duration */ 
	ePropertyID_StoryBoard_Loops = 1281, /*!< StoryBoard_Loops */ 
	ePropertyID_Rectangle_BackgroundR = 1536, /*!< Rectangle_BackgroundR */ 
	ePropertyID_Rectangle_BackgroundG = 1537, /*!< Rectangle_BackgroundG */ 
	ePropertyID_Rectangle_BackgroundB = 1538, /*!< Rectangle_BackgroundB */ 
	ePropertyID_Condition_Value = 2048, /*!< Condition_Value */ 
	ePropertyID_Label_BackgroundR = 2304, /*!< Label_BackgroundR */ 
	ePropertyID_Label_BackgroundG = 2305, /*!< Label_BackgroundG */ 
	ePropertyID_Label_BackgroundB = 2306, /*!< Label_BackgroundB */ 
	ePropertyID_Label_ForegroundR = 2307, /*!< Label_ForegroundR */ 
	ePropertyID_Label_ForegroundG = 2308, /*!< Label_ForegroundG */ 
	ePropertyID_Label_ForegroundB = 2309, /*!< Label_ForegroundB */ 
	ePropertyID_Label_Text = 2310, /*!< Label_Text */ 
	ePropertyID_Label_FontObject = 2311, /*!< Label_FontObject */ 
	ePropertyID_Label_HAlign = 2312, /*!< Label_HAlign */ 
	ePropertyID_Label_VAlign = 2313, /*!< Label_VAlign */ 
	ePropertyID_Label_FontSize = 2314, /*!< Label_FontSize */ 
	ePropertyID_Label_ObjID_Background = 2315, /*!< Label_ObjID_Background */ 
	ePropertyID_Label_Grayscale = 2316, /*!< Label_Grayscale */ 
	ePropertyID_Slider_BackgroundR = 2560, /*!< Slider_BackgroundR */ 
	ePropertyID_Slider_BackgroundG = 2561, /*!< Slider_BackgroundG */ 
	ePropertyID_Slider_BackgroundB = 2562, /*!< Slider_BackgroundB */ 
	ePropertyID_Slider_ForegroundR = 2563, /*!< Slider_ForegroundR */ 
	ePropertyID_Slider_ForegroundG = 2564, /*!< Slider_ForegroundG */ 
	ePropertyID_Slider_ForegroundB = 2565, /*!< Slider_ForegroundB */ 
	ePropertyID_Slider_Minimum = 2566, /*!< Slider_Minimum */ 
	ePropertyID_Slider_Maximum = 2567, /*!< Slider_Maximum */ 
	ePropertyID_Slider_Value = 2568, /*!< Slider_Value */ 
	ePropertyID_Slider_LabelText = 2569, /*!< Slider_LabelText */ 
	ePropertyID_Slider_LabelFontObject = 2570, /*!< Slider_LabelFontObject */ 
	ePropertyID_Slider_LabelR = 2571, /*!< Slider_LabelR */ 
	ePropertyID_Slider_LabelG = 2572, /*!< Slider_LabelG */ 
	ePropertyID_Slider_LabelB = 2573, /*!< Slider_LabelB */ 
	ePropertyID_Slider_Style = 2574, /*!< Slider_Style */ 
	ePropertyID_Slider_ObjID_NineForeGround = 2575, /*!< Slider_ObjID_NineForeGround */ 
	ePropertyID_Slider_ObjID_NineBackGround = 2576, /*!< Slider_ObjID_NineBackGround */ 
	ePropertyID_Slider_ObjID_NineButton = 2577, /*!< Slider_ObjID_NineButton */ 
	ePropertyID_Slider_ButtonWidth = 2578, /*!< Slider_ButtonWidth */ 
	ePropertyID_Slider_ButtonHeight = 2579, /*!< Slider_ButtonHeight */ 
	ePropertyID_Slider_EnableTouch = 2580, /*!< Slider_EnableTouch */ 
	ePropertyID_Slider_Direction = 2581, /*!< Slider_Direction */ 
	ePropertyID_Slider_TrackSize = 2582, /*!< Slider_TrackSize */ 
	ePropertyID_Slider_ObjID_Background = 2583, /*!< Slider_ObjID_Background */ 
	ePropertyID_Slider_ObjID_BitmapForeGround = 2584, /*!< Slider_ObjID_BitmapForeGround */ 
	ePropertyID_Slider_ObjID_BitmapBackGround = 2585, /*!< Slider_ObjID_BitmapBackGround */ 
	ePropertyID_Slider_ObjID_BitmapButton = 2586, /*!< Slider_ObjID_BitmapButton */ 
	ePropertyID_Slider_ButtonR = 2587, /*!< Slider_ButtonR */ 
	ePropertyID_Slider_ButtonG = 2588, /*!< Slider_ButtonG */ 
	ePropertyID_Slider_ButtonB = 2589, /*!< Slider_ButtonB */ 
	ePropertyID_Slider_DrawButton = 2590, /*!< Slider_DrawButton */ 
	ePropertyID_Slider_PadButton = 2591, /*!< Slider_PadButton */ 
	ePropertyID_Slider_LabelFontSize = 2592, /*!< Slider_LabelFontSize */ 
	ePropertyID_Slider_LabelOnButton = 2593, /*!< Slider_LabelOnButton */ 
	ePropertyID_Slider_Origin = 2594, /*!< Slider_Origin */ 
	ePropertyID_Slider_Offset = 2595, /*!< Slider_Offset */ 
	ePropertyID_Slider_ObjID_BitmapMask = 2596, /*!< Slider_ObjID_BitmapMask */ 
	ePropertyID_TraceBinding_TraceSlot = 4096, /*!< TraceBinding_TraceSlot */ 
	ePropertyID_TraceBinding_Value = 4097, /*!< TraceBinding_Value */ 
	ePropertyID_Button_BackgroundR = 5376, /*!< Button_BackgroundR */ 
	ePropertyID_Button_BackgroundG = 5377, /*!< Button_BackgroundG */ 
	ePropertyID_Button_BackgroundB = 5378, /*!< Button_BackgroundB */ 
	ePropertyID_Button_Text = 5379, /*!< Button_Text */ 
	ePropertyID_Button_FontObject = 5380, /*!< Button_FontObject */ 
	ePropertyID_Button_ForegroundR = 5381, /*!< Button_ForegroundR */ 
	ePropertyID_Button_ForegroundG = 5382, /*!< Button_ForegroundG */ 
	ePropertyID_Button_ForegroundB = 5383, /*!< Button_ForegroundB */ 
	ePropertyID_Button_FontSize = 5384, /*!< Button_FontSize */ 
	ePropertyID_Button_UpBitmap = 5385, /*!< Button_UpBitmap */ 
	ePropertyID_Button_DownBitmap = 5386, /*!< Button_DownBitmap */ 
	ePropertyID_Button_FocusBitmap = 5387, /*!< Button_FocusBitmap */ 
	ePropertyID_Button_State = 5388, /*!< Button_State */ 
	ePropertyID_Button_ButtonType = 5389, /*!< Button_ButtonType */ 
	ePropertyID_Button_DisabledBitmap = 5390, /*!< Button_DisabledBitmap */ 
	ePropertyID_Button_ButtonGroup = 5391, /*!< Button_ButtonGroup */ 
	ePropertyID_Button_DisabledR = 5392, /*!< Button_DisabledR */ 
	ePropertyID_Button_DisabledG = 5393, /*!< Button_DisabledG */ 
	ePropertyID_Button_DisabledB = 5394, /*!< Button_DisabledB */ 
	ePropertyID_Button_DownR = 5395, /*!< Button_DownR */ 
	ePropertyID_Button_DownG = 5396, /*!< Button_DownG */ 
	ePropertyID_Button_DownB = 5397, /*!< Button_DownB */ 
	ePropertyID_Button_CornerRadius = 5398, /*!< Button_CornerRadius */ 
	ePropertyID_GTTModule_Backlight = 6144, /*!< GTTModule_Backlight */ 
	ePropertyID_VisualBitmap_Source = 7936, /*!< VisualBitmap_Source */ 
	ePropertyID_VisualBitmap_SourceIndex = 7937, /*!< VisualBitmap_SourceIndex */ 
	ePropertyID_Animation_Master = 8192, /*!< Animation_Master */ 
	ePropertyID_Animation_MasterMode = 8193, /*!< Animation_MasterMode */ 
	ePropertyID_Animation_CurrentBitmap = 8194, /*!< Animation_CurrentBitmap */ 
	ePropertyID_Animation_Loops = 8195, /*!< Animation_Loops */ 
} ePropertyID;

/*! enum eTextEncoding */
typedef enum eTextEncoding {
	eTextEncoding_Unicode = 0, /*!< Unicode */ 
	eTextEncoding_ASCII = 1, /*!< ASCII */ 
	eTextEncoding_UTF8 = 2, /*!< UTF8 */ 
} eTextEncoding;

/*! enum eNeedleLocation */
typedef enum eNeedleLocation {
	eNeedleLocation_Center = 0, /*!< Center */ 
	eNeedleLocation_LeftTop = 1, /*!< LeftTop */ 
	eNeedleLocation_CenterTop = 2, /*!< CenterTop */ 
	eNeedleLocation_RightTop = 3, /*!< RightTop */ 
	eNeedleLocation_LeftMiddle = 4, /*!< LeftMiddle */ 
	eNeedleLocation_RightMiddle = 5, /*!< RightMiddle */ 
	eNeedleLocation_LeftBottom = 6, /*!< LeftBottom */ 
	eNeedleLocation_CenterBottom = 7, /*!< CenterBottom */ 
	eNeedleLocation_RightBottom = 8, /*!< RightBottom */ 
	eNeedleLocation_Pixel = 9, /*!< Pixel */ 
} eNeedleLocation;

/*! enum eNeedleMode */
typedef enum eNeedleMode {
	eNeedleMode_Classic = 0, /*!< Classic */ 
	eNeedleMode_Custom = 1, /*!< Custom */ 
} eNeedleMode;

/*! enum eEasing */
typedef enum eEasing {
	eEasing_Instant = 0, /*!< Instant */ 
	eEasing_linearTween = 1, /*!< linearTween */ 
	eEasing_InQuaduration = 2, /*!< InQuaduration */ 
	eEasing_OutQuaduration = 3, /*!< OutQuaduration */ 
	eEasing_InOutQuaduration = 4, /*!< InOutQuaduration */ 
	eEasing_InCubic = 5, /*!< InCubic */ 
	eEasing_OutCubic = 6, /*!< OutCubic */ 
	eEasing_InOutCubic = 7, /*!< InOutCubic */ 
	eEasing_InQuart = 8, /*!< InQuart */ 
	eEasing_OutQuart = 9, /*!< OutQuart */ 
	eEasing_InOutQuart = 10, /*!< InOutQuart */ 
	eEasing_InQuint = 10, /*!< InQuint */ 
	eEasing_OutQuint = 12, /*!< OutQuint */ 
	eEasing_InOutQuint = 13, /*!< InOutQuint */ 
	eEasing_InSine = 14, /*!< InSine */ 
	eEasing_OutSine = 15, /*!< OutSine */ 
	eEasing_InOutSine = 16, /*!< InOutSine */ 
	eEasing_InExponential = 17, /*!< InExponential */ 
	eEasing_OutExponential = 18, /*!< OutExponential */ 
	eEasing_InOutExponential = 19, /*!< InOutExponential */ 
	eEasing_InCircular = 20, /*!< InCircular */ 
	eEasing_OutCircular = 21, /*!< OutCircular */ 
	eEasing_InOutCircular = 22, /*!< InOutCircular */ 
} eEasing;

/*! enum eAction */
typedef enum eAction {
	eAction_StartStoryBoard = 1, /*!< StartStoryBoard */ 
	eAction_SetValue = 2, /*!< SetValue */ 
} eAction;

/*! enum eLogicalComparison */
typedef enum eLogicalComparison {
	eLogicalComparison_LogicalAnd = 0, /*!< LogicalAnd */ 
	eLogicalComparison_LogicalOr = 1, /*!< LogicalOr */ 
	eLogicalComparison_LogicalXor = 2, /*!< LogicalXor */ 
	eLogicalComparison_LogicalAndNot = 3, /*!< LogicalAndNot */ 
} eLogicalComparison;

/*! enum eComparison */
typedef enum eComparison {
	eComparison_Equal = 0, /*!< Equal */ 
	eComparison_NOT_Equal = 1, /*!< NOT_Equal */ 
	eComparison_Greater = 2, /*!< Greater */ 
	eComparison_GreaterEqual = 3, /*!< GreaterEqual */ 
	eComparison_Less = 4, /*!< Less */ 
	eComparison_LessEqual = 5, /*!< LessEqual */ 
} eComparison;

/*! enum eLabelHorizontalAlignment */
typedef enum eLabelHorizontalAlignment {
	eLabelHorizontalAlignment_Center = 0, /*!< Center */ 
	eLabelHorizontalAlignment_Left = 1, /*!< Left */ 
	eLabelHorizontalAlignment_Right = 2, /*!< Right */ 
} eLabelHorizontalAlignment;

/*! enum eLabelVerticalAlignment */
typedef enum eLabelVerticalAlignment {
	eLabelVerticalAlignment_Center = 0, /*!< Center */ 
	eLabelVerticalAlignment_Top = 1, /*!< Top */ 
	eLabelVerticalAlignment_Bottom = 2, /*!< Bottom */ 
} eLabelVerticalAlignment;

/*! enum eSliderStyle */
typedef enum eSliderStyle {
	eSliderStyle_Solid = 0, /*!< Solid */ 
	eSliderStyle_NineSlice = 1, /*!< NineSlice */ 
	eSliderStyle_Bitmap = 2, /*!< Bitmap */ 
	eSliderStyle_SlidingBitmap = 3, /*!< SlidingBitmap */ 
	eSliderStyle_GradientMaskedBitmap = 4, /*!< GradientMaskedBitmap */ 
} eSliderStyle;

/*! enum eSliderDirection */
typedef enum eSliderDirection {
	eSliderDirection_Horizontal = 0, /*!< Horizontal */ 
	eSliderDirection_Vertical = 1, /*!< Vertical */ 
	eSliderDirection_Auto = 2, /*!< Auto */ 
} eSliderDirection;

/*! enum eSliderOrigin */
typedef enum eSliderOrigin {
	eSliderOrigin_Standard = 0, /*!< Standard */ 
	eSliderOrigin_Center = 1, /*!< Center */ 
	eSliderOrigin_Offset = 2, /*!< Offset */ 
} eSliderOrigin;

/*! enum eMathOperation */
typedef enum eMathOperation {
	eMathOperation_Add = 0, /*!< Add */ 
	eMathOperation_Subtract = 1, /*!< Subtract */ 
	eMathOperation_Multiply = 2, /*!< Multiply */ 
	eMathOperation_Divide = 3, /*!< Divide */ 
	eMathOperation_Greater = 4, /*!< Greater */ 
	eMathOperation_GreaterEqual = 5, /*!< GreaterEqual */ 
	eMathOperation_Equal = 6, /*!< Equal */ 
	eMathOperation_LessEqual = 7, /*!< LessEqual */ 
	eMathOperation_Less = 8, /*!< Less */ 
} eMathOperation;

/*! enum eButtonState */
typedef enum eButtonState {
	eButtonState_Up = 0, /*!< Up */ 
	eButtonState_Down = 1, /*!< Down */ 
	eButtonState_Disabled = 2, /*!< Disabled */ 
} eButtonState;

/*! enum eButtonType */
typedef enum eButtonType {
	eButtonType_Regular = 0, /*!< Regular */ 
	eButtonType_Toggle = 1, /*!< Toggle */ 
	eButtonType_GroupToggle = 2, /*!< GroupToggle */ 
} eButtonType;

/*! enum eDirectWritePixelFormat */
typedef enum eDirectWritePixelFormat {
	eDirectWritePixelFormat_rgb565 = 0, /*!< rgb565 */ 
	eDirectWritePixelFormat_i4 = 1, /*!< i4 */ 
	eDirectWritePixelFormat_i8 = 2, /*!< i8 */ 
} eDirectWritePixelFormat;

/*! enum eStartupMode */
typedef enum eStartupMode {
	eStartupMode_Normal = 0, /*!< Normal */ 
	eStartupMode_Watchdog = 1, /*!< Watchdog */ 
	eStartupMode_Brownout = 2, /*!< Brownout */ 
	eStartupMode_ResetCMD = 3, /*!< ResetCMD */ 
} eStartupMode;

/*! enum eAnimationMaterMode */
typedef enum eAnimationMaterMode {
	eAnimationMaterMode_None = 0, /*!< None */ 
	eAnimationMaterMode_Clock = 1, /*!< Clock */ 
	eAnimationMaterMode_Run = 2, /*!< Run */ 
} eAnimationMaterMode;

/*! enum eGtt25Command */
typedef enum eGtt25Command {
	eGtt25Command_BaseObject_Create = 256, /*!< BaseObject_Create */ 
	eGtt25Command_BaseObject_Destroy = 257, /*!< BaseObject_Destroy */ 
	eGtt25Command_BaseObject_BeginUpdate = 258, /*!< BaseObject_BeginUpdate */ 
	eGtt25Command_BaseObject_EndUpdate = 259, /*!< BaseObject_EndUpdate */ 
	eGtt25Command_BaseObject_SetPropertyU8 = 260, /*!< BaseObject_SetPropertyU8 */ 
	eGtt25Command_BaseObject_GetPropertyU8 = 261, /*!< BaseObject_GetPropertyU8 */ 
	eGtt25Command_BaseObject_SetPropertyU16 = 262, /*!< BaseObject_SetPropertyU16 */ 
	eGtt25Command_BaseObject_GetPropertyU16 = 263, /*!< BaseObject_GetPropertyU16 */ 
	eGtt25Command_BaseObject_SetPropertyS16 = 264, /*!< BaseObject_SetPropertyS16 */ 
	eGtt25Command_BaseObject_GetPropertyS16 = 265, /*!< BaseObject_GetPropertyS16 */ 
	eGtt25Command_BaseObject_SetPropertyText = 266, /*!< BaseObject_SetPropertyText */ 
	eGtt25Command_BaseObject_GetPropertyText = 267, /*!< BaseObject_GetPropertyText */ 
	eGtt25Command_BaseObject_SetPropertyEval = 268, /*!< BaseObject_SetPropertyEval */ 
	eGtt25Command_BaseObject_DestroyAll = 269, /*!< BaseObject_DestroyAll */ 
	eGtt25Command_BaseObject_GetObjectType = 270, /*!< BaseObject_GetObjectType */ 
	eGtt25Command_BaseObject_AppendPropertyText = 273, /*!< BaseObject_AppendPropertyText */ 
	eGtt25Command_BaseObject_SetEventHandler = 280, /*!< BaseObject_SetEventHandler */ 
	eGtt25Command_BaseObject_SetPropertyFloat = 281, /*!< BaseObject_SetPropertyFloat */ 
	eGtt25Command_BaseObject_GetPropertyFloat = 282, /*!< BaseObject_GetPropertyFloat */ 
	eGtt25Command_BaseObject_ProcessChanges = 285, /*!< BaseObject_ProcessChanges */ 
	eGtt25Command_VisualObject_Invalidate = 512, /*!< VisualObject_Invalidate */ 
	eGtt25Command_VisualObject_AddDependency = 513, /*!< VisualObject_AddDependency */ 
	eGtt25Command_VisualObject_SetFocus = 514, /*!< VisualObject_SetFocus */ 
	eGtt25Command_VisualObject_NextFocus = 515, /*!< VisualObject_NextFocus */ 
	eGtt25Command_VisualObject_PrevFocus = 516, /*!< VisualObject_PrevFocus */ 
	eGtt25Command_VisualObject_GlobalNextFocus = 517, /*!< VisualObject_GlobalNextFocus */ 
	eGtt25Command_VisualObject_GlobalPrevFocus = 518, /*!< VisualObject_GlobalPrevFocus */ 
	eGtt25Command_StrokePad_Clear = 1024, /*!< StrokePad_Clear */ 
	eGtt25Command_StrokePad_GetStrokeCount = 1025, /*!< StrokePad_GetStrokeCount */ 
	eGtt25Command_StrokePad_GetStroke = 1026, /*!< StrokePad_GetStroke */ 
	eGtt25Command_StoryBoard_SetValueU8 = 1281, /*!< StoryBoard_SetValueU8 */ 
	eGtt25Command_StoryBoard_SetValueU16 = 1282, /*!< StoryBoard_SetValueU16 */ 
	eGtt25Command_StoryBoard_SetValueS16 = 1283, /*!< StoryBoard_SetValueS16 */ 
	eGtt25Command_StoryBoard_SetValueU32 = 1284, /*!< StoryBoard_SetValueU32 */ 
	eGtt25Command_StoryBoard_Start = 1285, /*!< StoryBoard_Start */ 
	eGtt25Command_StoryBoard_Stop = 1286, /*!< StoryBoard_Stop */ 
	eGtt25Command_StoryBoard_AnimateValueU8 = 1287, /*!< StoryBoard_AnimateValueU8 */ 
	eGtt25Command_StoryBoard_AnimateValueS16 = 1288, /*!< StoryBoard_AnimateValueS16 */ 
	eGtt25Command_StoryBoard_SetValueString = 1289, /*!< StoryBoard_SetValueString */ 
	eGtt25Command_StoryBoard_Beep = 1290, /*!< StoryBoard_Beep */ 
	eGtt25Command_StoryBoard_AnimateValueU16 = 1291, /*!< StoryBoard_AnimateValueU16 */ 
	eGtt25Command_Trigger_CreateTrigger = 1792, /*!< Trigger_CreateTrigger */ 
	eGtt25Command_Trigger_SetPropertyEval = 1793, /*!< Trigger_SetPropertyEval */ 
	eGtt25Command_Condition_CreatePropertyU8 = 2048, /*!< Condition_CreatePropertyU8 */ 
	eGtt25Command_Condition_CreatePropertyU16 = 2049, /*!< Condition_CreatePropertyU16 */ 
	eGtt25Command_Condition_CreateLogical = 2050, /*!< Condition_CreateLogical */ 
	eGtt25Command_DataBinding_SetupBinding = 2816, /*!< DataBinding_SetupBinding */ 
	eGtt25Command_DataBinding_SetupEvalBinding = 2817, /*!< DataBinding_SetupEvalBinding */ 
	eGtt25Command_NineSlice_Load = 3072, /*!< NineSlice_Load */ 
	eGtt25Command_Bitmap_Load = 3328, /*!< Bitmap_Load */ 
	eGtt25Command_Bitmap_Capture = 3329, /*!< Bitmap_Capture */ 
	eGtt25Command_Font_Load = 3584, /*!< Font_Load */ 
	eGtt25Command_Font_Cache = 3585, /*!< Font_Cache */ 
	eGtt25Command_Font_ClearCache = 3586, /*!< Font_ClearCache */ 
	eGtt25Command_Font_ClearCacheAll = 3587, /*!< Font_ClearCacheAll */ 
	eGtt25Command_Font_SetAutoCacheSizeLimit = 3588, /*!< Font_SetAutoCacheSizeLimit */ 
	eGtt25Command_FileSystem_GetFileSize = 3840, /*!< FileSystem_GetFileSize */ 
	eGtt25Command_FileSystem_GetFreeSpace = 3841, /*!< FileSystem_GetFreeSpace */ 
	eGtt25Command_FileSystem_Move = 3842, /*!< FileSystem_Move */ 
	eGtt25Command_FileSystem_GetCRC = 3843, /*!< FileSystem_GetCRC */ 
	eGtt25Command_FileSystem_GetFiles = 3844, /*!< FileSystem_GetFiles */ 
	eGtt25Command_FileSystem_CreateFolder = 3845, /*!< FileSystem_CreateFolder */ 
	eGtt25Command_FileSystem_DeleteFolder = 3846, /*!< FileSystem_DeleteFolder */ 
	eGtt25Command_FileSystem_FileWrite = 3847, /*!< FileSystem_FileWrite */ 
	eGtt25Command_FileSystem_FileRead = 3848, /*!< FileSystem_FileRead */ 
	eGtt25Command_FileSystem_FileDelete = 3849, /*!< FileSystem_FileDelete */ 
	eGtt25Command_FileSystem_StartXmodemUpload = 3850, /*!< FileSystem_StartXmodemUpload */ 
	eGtt25Command_FileSystem_TestMethod = 3851, /*!< FileSystem_TestMethod */ 
	eGtt25Command_GTTModule_SetupUSBDirectWrite = 6144, /*!< GTTModule_SetupUSBDirectWrite */ 
	eGtt25Command_GTTModule_SetupUSBDirectWritePalette = 6145, /*!< GTTModule_SetupUSBDirectWritePalette */ 
	eGtt25Command_GTTModule_GetLastStartupFlag = 6146, /*!< GTTModule_GetLastStartupFlag */ 
	eGtt25Command_GTTModule_Reset = 6147, /*!< GTTModule_Reset */ 
	eGtt25Command_GTTModule_SetMACAddressMethod = 6148, /*!< GTTModule_SetMACAddressMethod */ 
	eGtt25Command_GTTModule_GetMACAddressMethod = 6149, /*!< GTTModule_GetMACAddressMethod */ 
	eGtt25Command_ObjectList_Add = 6656, /*!< ObjectList_Add */ 
	eGtt25Command_ObjectList_Remove = 6657, /*!< ObjectList_Remove */ 
	eGtt25Command_ObjectList_Count = 6658, /*!< ObjectList_Count */ 
	eGtt25Command_ObjectList_Get = 6659, /*!< ObjectList_Get */ 
	eGtt25Command_ObjectList_Clear = 6660, /*!< ObjectList_Clear */ 
	eGtt25Command_Animation_AddFrame = 8192, /*!< Animation_AddFrame */ 
	eGtt25Command_Animation_Start = 8193, /*!< Animation_Start */ 
	eGtt25Command_Animation_Stop = 8194, /*!< Animation_Stop */ 
	eGtt25Command_EventGraph_CreateNode = 16896, /*!< EventGraph_CreateNode */ 
	eGtt25Command_EventGraph_AddLink = 16897, /*!< EventGraph_AddLink */ 
	eGtt25Command_EventGraph_SetNodeValueText = 16898, /*!< EventGraph_SetNodeValueText */ 
	eGtt25Command_EventGraph_SetNodeValueU8 = 16899, /*!< EventGraph_SetNodeValueU8 */ 
	eGtt25Command_EventGraph_SetNodeValueU16 = 16900, /*!< EventGraph_SetNodeValueU16 */ 
	eGtt25Command_EventGraph_SetNodeValueFloat = 16901, /*!< EventGraph_SetNodeValueFloat */ 
} eGtt25Command;

/*! enum eFlowControl */
typedef enum eFlowControl {
	eFlowControl_Off = 0, /*!< Off */ 
	eFlowControl_RTSCTS = 1, /*!< RTSCTS */ 
} eFlowControl;

/*! enum eControlCharacterMode */
typedef enum eControlCharacterMode {
	eControlCharacterMode_Unix = 0, /*!< Unix */ 
	eControlCharacterMode_Windows = 1, /*!< Windows */ 
} eControlCharacterMode;

/*! enum eOnOff */
typedef enum eOnOff {
	eOnOff_Off = 0, /*!< Off */ 
	eOnOff_On = 1, /*!< On */ 
} eOnOff;

/*! enum eAnimationState */
typedef enum eAnimationState {
	eAnimationState_Paused = 0, /*!< Paused */ 
	eAnimationState_Playing = 1, /*!< Playing */ 
} eAnimationState;

/*! enum eEnable */
typedef enum eEnable {
	eEnable_Disable = 0, /*!< Disable */ 
	eEnable_Enable = 1, /*!< Enable */ 
} eEnable;

/*! enum eActivation */
typedef enum eActivation {
	eActivation_Inactive = 0, /*!< Inactive */ 
	eActivation_Active = 1, /*!< Active */ 
} eActivation;

/*! enum eTouchReportingType */
typedef enum eTouchReportingType {
	eTouchReportingType_RegionNone = 0, /*!< RegionNone */ 
	eTouchReportingType_RegionDown = 1, /*!< RegionDown */ 
	eTouchReportingType_RegionUp = 2, /*!< RegionUp */ 
	eTouchReportingType_RegionUpDown = 3, /*!< RegionUpDown */ 
	eTouchReportingType_RegionMove = 4, /*!< RegionMove */ 
	eTouchReportingType_RegionMoveDown = 5, /*!< RegionMoveDown */ 
	eTouchReportingType_RegionMoveUp = 6, /*!< RegionMoveUp */ 
	eTouchReportingType_RegionMoveUpDown = 7, /*!< RegionMoveUpDown */ 
	eTouchReportingType_CoordNone = 8, /*!< CoordNone */ 
	eTouchReportingType_CoordDown = 9, /*!< CoordDown */ 
	eTouchReportingType_CoordUp = 10, /*!< CoordUp */ 
	eTouchReportingType_CoordUpDown = 11, /*!< CoordUpDown */ 
	eTouchReportingType_CoordMove = 12, /*!< CoordMove */ 
	eTouchReportingType_CoordMoveDown = 13, /*!< CoordMoveDown */ 
	eTouchReportingType_CoordMoveUp = 14, /*!< CoordMoveUp */ 
	eTouchReportingType_CoordMoveUpDown = 15, /*!< CoordMoveUpDown */ 
} eTouchReportingType;

/*! enum eKeypadInputOutputType */
typedef enum eKeypadInputOutputType {
	eKeypadInputOutputType_None = 0, /*!< None */ 
	eKeypadInputOutputType_OutputBeep = 1, /*!< OutputBeep */ 
	eKeypadInputOutputType_OutputMotor = 2, /*!< OutputMotor */ 
	eKeypadInputOutputType_InputKeypad = 4, /*!< InputKeypad */ 
	eKeypadInputOutputType_InputTouch = 8, /*!< InputTouch */ 
} eKeypadInputOutputType;

/*! enum eKeypadRepeatMode */
typedef enum eKeypadRepeatMode {
	eKeypadRepeatMode_Off = 0, /*!< Off */ 
	eKeypadRepeatMode_Hold = 1, /*!< Hold */ 
	eKeypadRepeatMode_Typematic = 2, /*!< Typematic */ 
} eKeypadRepeatMode;

/*! enum eGPOSetting */
typedef enum eGPOSetting {
	eGPOSetting_On = 1, /*!< On */ 
	eGPOSetting_Off = 0, /*!< Off */ 
} eGPOSetting;

/*! enum eChannel */
typedef enum eChannel {
	eChannel_None = 0, /*!< None */ 
	eChannel_Serial = 1, /*!< Serial */ 
	eChannel_I2C = 2, /*!< I2C */ 
	eChannel_USBMassStorage = 3, /*!< USBMassStorage */ 
	eChannel_CAN = 4, /*!< CAN */ 
	eChannel_SPI = 5, /*!< SPI */ 
	eChannel_Current = 255, /*!< Current */ 
} eChannel;

/*! enum eStatusCode */
typedef enum eStatusCode {
	eStatusCode_FileNotFound = 0, /*!< FileNotFound */ 
	eStatusCode_InvalidBitmapFileFormat = 1, /*!< InvalidBitmapFileFormat */ 
	eStatusCode_Invalid9SliceMetrics = 2, /*!< Invalid9SliceMetrics */ 
	eStatusCode_Invalid9SliceIndex = 3, /*!< Invalid9SliceIndex */ 
	eStatusCode_InvalidBitmapIndex = 4, /*!< InvalidBitmapIndex */ 
	eStatusCode_InvalidBargraphIndex = 5, /*!< InvalidBargraphIndex */ 
	eStatusCode_InvalidAnimationIndex = 6, /*!< InvalidAnimationIndex */ 
	eStatusCode_InvalidAnimationFileFormat = 7, /*!< InvalidAnimationFileFormat */ 
	eStatusCode_InvalidFontIndex = 8, /*!< InvalidFontIndex */ 
	eStatusCode_InvalidCommandParameters = 9, /*!< InvalidCommandParameters */ 
	eStatusCode_DisplayisOUTofRAM = 10, /*!< DisplayisOUTofRAM */ 
	eStatusCode_InvalidRegionFileFormat = 11, /*!< InvalidRegionFileFormat */ 
	eStatusCode_InvalidTouchCalibration = 12, /*!< InvalidTouchCalibration */ 
	eStatusCode_SuccessfulTouchCalibration = 13, /*!< SuccessfulTouchCalibration */ 
	eStatusCode_InvalidFileFormat = 14, /*!< InvalidFileFormat */ 
	eStatusCode_InvalidTraceIndex = 15, /*!< InvalidTraceIndex */ 
	eStatusCode_InvalidTouchRegion = 16, /*!< InvalidTouchRegion */ 
	eStatusCode_InvalidLabelIndex = 17, /*!< InvalidLabelIndex */ 
	eStatusCode_Success = 254, /*!< Success */ 
	eStatusCode_UnknownException = 255, /*!< UnknownException */ 
} eStatusCode;

/*! enum eCalibrationErrorCode */
typedef enum eCalibrationErrorCode {
	eCalibrationErrorCode_CalibrationSuccessful = 1, /*!< CalibrationSuccessful */ 
	eCalibrationErrorCode_CalibrationInvalid = 12, /*!< CalibrationInvalid */ 
} eCalibrationErrorCode;

/*! enum eRestoreCalibrationErrorCode */
typedef enum eRestoreCalibrationErrorCode {
	eRestoreCalibrationErrorCode_RestoreCalibrationInvalid = 0, /*!< RestoreCalibrationInvalid */ 
	eRestoreCalibrationErrorCode_RestoreCalibrationSuccessful = 1, /*!< RestoreCalibrationSuccessful */ 
} eRestoreCalibrationErrorCode;

/*! enum eBargraphOrientation */
typedef enum eBargraphOrientation {
	eBargraphOrientation_BottomToTop = 0, /*!< BottomToTop */ 
	eBargraphOrientation_LeftToRight = 1, /*!< LeftToRight */ 
	eBargraphOrientation_RightToLeft = 2, /*!< RightToLeft */ 
	eBargraphOrientation_TopToBottom = 3, /*!< TopToBottom */ 
} eBargraphOrientation;

/*! enum eBargraphType */
typedef enum eBargraphType {
	eBargraphType_Unused = 0, /*!< Unused */ 
	eBargraphType_Plain = 1, /*!< Plain */ 
	eBargraphType_NineSlice = 2, /*!< NineSlice */ 
} eBargraphType;

/*! enum eTouchReport */
typedef enum eTouchReport {
	eTouchReport_Down = 0, /*!< Down */ 
	eTouchReport_Up = 1, /*!< Up */ 
	eTouchReport_Move = 2, /*!< Move */ 
	eTouchReport_OutOfRegion = 255, /*!< OutOfRegion */ 
} eTouchReport;

/*! enum eKeypadReport */
typedef enum eKeypadReport {
	eKeypadReport_Press = 0, /*!< Press */ 
	eKeypadReport_Release = 1, /*!< Release */ 
	eKeypadReport_Repeat = 2, /*!< Repeat */ 
} eKeypadReport;

/*! enum eModule */
typedef enum eModule {
	eModule_GTT35A = 37638, /*!< GTT35A */ 
	eModule_GTT38A = 37648, /*!< GTT38A */ 
	eModule_GTT43A = 37633, /*!< GTT43A */ 
	eModule_GTT50A = 37634, /*!< GTT50A */ 
	eModule_GTT57A = 37635, /*!< GTT57A */ 
	eModule_GTT70A = 37636, /*!< GTT70A */ 
} eModule;

/*! enum eBuffers */
typedef enum eBuffers {
	eBuffers_Animations = 0, /*!< Animations */ 
	eBuffers_Bitmaps = 1, /*!< Bitmaps */ 
	eBuffers_NineSlices = 2, /*!< NineSlices */ 
	eBuffers_Fonts = 3, /*!< Fonts */ 
	eBuffers_Labels = 4, /*!< Labels */ 
	eBuffers_Traces = 5, /*!< Traces */ 
} eBuffers;

/*! enum eAnchorType */
typedef enum eAnchorType {
	eAnchorType_UpperLeft = 0, /*!< UpperLeft */ 
	eAnchorType_BaseLine = 1, /*!< BaseLine */ 
} eAnchorType;

/*! enum eFontRenderType */
typedef enum eFontRenderType {
	eFontRenderType_Grayscale = 0, /*!< Grayscale */ 
	eFontRenderType_Monochrome = 1, /*!< Monochrome */ 
} eFontRenderType;

/*! enum eFontAlignHorizontal */
typedef enum eFontAlignHorizontal {
	eFontAlignHorizontal_Left = 0, /*!< Left */ 
	eFontAlignHorizontal_Right = 1, /*!< Right */ 
	eFontAlignHorizontal_Center = 2, /*!< Center */ 
} eFontAlignHorizontal;

/*! enum eFontAlignVertical */
typedef enum eFontAlignVertical {
	eFontAlignVertical_Top = 0, /*!< Top */ 
	eFontAlignVertical_Bottom = 1, /*!< Bottom */ 
	eFontAlignVertical_Center = 2, /*!< Center */ 
} eFontAlignVertical;

/*! enum eTraceTypeandDirection */
typedef enum eTraceTypeandDirection {
	eTraceTypeandDirection_Bar = 0, /*!< Bar */ 
	eTraceTypeandDirection_Line = 1, /*!< Line */ 
	eTraceTypeandDirection_Step = 2, /*!< Step */ 
	eTraceTypeandDirection_Box = 3, /*!< Box */ 
	eTraceTypeandDirection_BottomLeft = 0, /*!< BottomLeft */ 
	eTraceTypeandDirection_ShiftTowardOrigin = 0, /*!< ShiftTowardOrigin */ 
	eTraceTypeandDirection_LeftUp = 16, /*!< LeftUp */ 
	eTraceTypeandDirection_TopRight = 32, /*!< TopRight */ 
	eTraceTypeandDirection_RightDown = 48, /*!< RightDown */ 
	eTraceTypeandDirection_BottomRight = 64, /*!< BottomRight */ 
	eTraceTypeandDirection_ShiftAwayFromOrigin = 128, /*!< ShiftAwayFromOrigin */ 
	eTraceTypeandDirection_LeftDown = 80, /*!< LeftDown */ 
	eTraceTypeandDirection_TopLeft = 96, /*!< TopLeft */ 
	eTraceTypeandDirection_RightUp = 112, /*!< RightUp */ 
} eTraceTypeandDirection;

/*! enum ePixelFormat */
typedef enum ePixelFormat {
	ePixelFormat_RGB16 = 0, /*!< RGB16 */ 
	ePixelFormat_RGB24 = 1, /*!< RGB24 */ 
	ePixelFormat_BGR24 = 3, /*!< BGR24 */ 
} ePixelFormat;

/*! enum eSliderStyles */
typedef enum eSliderStyles {
	eSliderStyles_Vertical = 0, /*!< Vertical */ 
	eSliderStyles_Horizontal = 1, /*!< Horizontal */ 
} eSliderStyles;

/*! enum eSlidingBarStyles */
typedef enum eSlidingBarStyles {
	eSlidingBarStyles_BottomToTop = 0, /*!< BottomToTop */ 
	eSlidingBarStyles_LeftToRight = 1, /*!< LeftToRight */ 
	eSlidingBarStyles_RightToLeft = 2, /*!< RightToLeft */ 
	eSlidingBarStyles_TopToBottom = 3, /*!< TopToBottom */ 
} eSlidingBarStyles;

/*! enum ePanelOrientation */
typedef enum ePanelOrientation {
	ePanelOrientation_Landscape = 0, /*!< Landscape */ 
	ePanelOrientation_PortraitClockwise = 1, /*!< PortraitClockwise */ 
	ePanelOrientation_LandscapeFlipped = 2, /*!< LandscapeFlipped */ 
	ePanelOrientation_PortraitCounterClockwise = 3, /*!< PortraitCounterClockwise */ 
} ePanelOrientation;

/*! enum eIndicatorState */
typedef enum eIndicatorState {
	eIndicatorState_Off = 0, /*!< Off */ 
	eIndicatorState_Green = 1, /*!< Green */ 
	eIndicatorState_Red = 2, /*!< Red */ 
	eIndicatorState_Yellow = 3, /*!< Yellow */ 
} eIndicatorState;

/*! enum eAutoBacklight */
typedef enum eAutoBacklight {
	eAutoBacklight_TransmitKeyNoLightChange = 0, /*!< TransmitKeyNoLightChange */ 
	eAutoBacklight_TransmitKeyLightBacklight = 1, /*!< TransmitKeyLightBacklight */ 
	eAutoBacklight_OmitKeyNoLightChange = 8, /*!< OmitKeyNoLightChange */ 
	eAutoBacklight_OmitKeyLightBacklight = 9, /*!< OmitKeyLightBacklight */ 
} eAutoBacklight;

#ifdef __cplusplus
}
#endif
#endif

