function WriteFeed()
	MeasurePath 	= SKIN:GetMeasure("GetPath")
	MeasureName 	= SKIN:GetMeasure("GetName")	
	MeasureLink 	= SKIN:GetMeasure("GetLink")
	MeasureFeed 	= SKIN:GetMeasure("GetFeed")
	MeasureSect 	= SKIN:GetMeasure("GetStorySect")
	MeasureLnkI 	= SKIN:GetMeasure("GetLinkIndex")
	MeasureImgI 	= SKIN:GetMeasure("GetImageIndex")

	filename 	= MeasurePath:GetStringValue() .. MeasureName:GetStringValue() .. ".inc"

	variables 	= "[Variables]" .. "\n"
	mainURL 		= "mainURL=" 	.. MeasureLink:GetStringValue() .. "\n"
	URL 			= "URL=" 		.. MeasureFeed:GetStringValue() .. "\n"
	storySect 	= "storysect=" 	.. MeasureSect:GetStringValue() .. "\n"
	Captures 		= "Captures=3" 		.. "\n"
	TitleIndex 	= "TitleIndex=-2"	.. "\n"
	LinkIndex 	= "LinkIndex=" 	.. MeasureLnkI:GetStringValue() .. "\n"
	ImageIndex 	= "ImageIndex=" .. MeasureImgI:GetStringValue() .. "\n"

	compiled = variables .. mainURL .. URL .. storySect .. Captures .. TitleIndex .. LinkIndex .. ImageIndex

	OutputFile = io.open(filename, "w")
	OutputFile:write(compiled)
	OutputFile:close()
end

function AddEvent()
	MeasurePath 	= SKIN:GetMeasure("GetPath")
	filename 	=  MeasurePath:GetStringValue()
	compiled = "asdsa!"
	
	OutputFile = io.open(filename, "w")
	OutputFile:write(compiled)
	OutputFile:close()
end
