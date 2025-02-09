--SKIN:Bang("!SetOption TestMe Text \"5\"")
--SKIN:Bang("!SetOption TestMe Text "..Week..Day)

-- Sets up variables for the script to use
function Initialize()
	txt_dayA = {"January","February","March","April","May","June","July","August","September","October","November","December"}
	
	--Meters we will be pulling from
	mMonthToday = SKIN:GetMeasure('mMonthToday')
	mMonth = SKIN:GetMeasure('mMonth')
	mYear = SKIN:GetMeasure("mYear")
	mDays = SKIN:GetMeasure("mDayCount")
	mMonthStart = SKIN:GetMeasure('cMonthStart')
	mToday = SKIN:GetMeasure("MCDate")
	mDay = SKIN:GetMeasure("mDay")
	boxX = SKIN:GetMeasure("boxX")
	boxY = SKIN:GetMeasure("boxY")
	boxW = SKIN:GetMeasure("boxW")
	boxH = SKIN:GetMeasure("boxH")
	gapX = SKIN:GetMeasure("gapX")
	

	timeMode = "%#I:%M%p"
	--Lua arrays start with 1!
	reload = 1	
	
end -- function Initialize

--Updates the skin if there is a change
function Update()
	if(reload == 1) then
		Arrange()
	end
end


function Arrange()
	day = tonumber(mMonthStart:GetValue())
	month = tonumber(mMonth:GetValue())
	year = tonumber(mYear:GetValue())
	
	x = tonumber(boxX:GetValue())
	y = tonumber(boxY:GetValue()) 
	w = tonumber(boxW:GetValue())
	h = tonumber(boxH:GetValue())
	
	days = tonumber(mDays:GetValue())
	
	today = tonumber(mToday:GetValue())
	thisMonth = tonumber(mMonthToday:GetValue())
	
	SKIN:Bang("!UpdateMeasure cMonthStart")
	for d = 1, 31 do 
		box = "b" .. d
		newX = x + (w * (day-1)) 

		--Hide this box if it is not on our calendar
		if d > days then
			SKIN:Bang("!SetOption " .. d .. " Hidden 1")
			SKIN:Bang("!SetOption " .. box .. " Hidden 1")
			
		--Otherwise, work with it!
		else
			SKIN:Bang("!SetOption " .. d .. " Hidden 0")		
			SKIN:Bang("!SetOption " .. box .. " Hidden 0")

			--Move the text and box into position
			SKIN:Bang("!SetOption " .. d .. " X " .. newX)
			SKIN:Bang("!SetOption " .. d .. " Y " .. y + h/4)
			SKIN:Bang("!SetOption " .. box .. " X " .. newX)
			SKIN:Bang("!SetOption " .. box .. " Y " .. y)

				
			--Is this box TODAY?
			if d == today and month == thisMonth then			
				SKIN:Bang('!SetOption ' .. d .. ' FontColor \#white\#')
				SKIN:Bang("!SetOption TodayHL X " .. newX)
				SKIN:Bang("!SetOption TodayHL Y " .. y)
			else
				SKIN:Bang('!SetOption ' .. d .. ' FontColor \#txColor\#')
			end
			
			
			--Check if this day has an Event	
			Event = SKIN:GetVariable(d .."|"..month.."|"..year)
			EventText = 'error'
			
			
			--Returns a value of 1 if this variable is in our list of events in data_B
			if tonumber(Event) == 1 then
				SKIN:Bang('!SetOption ' .. d .. ' FontColor \#EventColor\#')
				EventText = SKIN:GetVariable(d .."|"..month.."|"..year..'T')
				local s = string.gsub(EventText,"•","\#CRLF\#")
				SKIN:Bang('!SetOption '.. d .. ' PostFix \"\"\"\n\n'..s..'\"\"\"')
				SKIN:Bang('!SetOption '.. d .. ' ToolTipText \"' .. month .. "/" .. d .. '\n'..s..'\"')
				
				if d == today then
					SKIN:Bang("!ShowMeterGroup alarm")
					SKIN:Bang("!SetOption AlarmText Text " .. EventText)
				end
			else
				SKIN:Bang('!SetOption '.. d .. ' PostFix \" \"')
				SKIN:Bang('!SetOption '.. d .. ' ToolTipText \"\"')
			end
		end
		
		--Go to the next day of the week
		day = day + 1
		if day > 7 then 
			day = 1
			y = y + h
		end			
	end
	reload = 0
end 

function ShowEvent()
	month = tonumber(mMonth:GetValue())
	year = tonumber(mYear:GetValue())
	Event = SKIN:GetVariable(SELF:GetOption('Hover').."|"..month.."|"..year)
	--SKIN:Bang('!SetOption EventText Text '..EventText)
	if tonumber(Event) == 1 then
		EventText = SKIN:GetVariable(SELF:GetOption('Hover').."|"..month.."|"..year..'T')
		SKIN:Bang('!SetOption EventText Text \"'..EventText.. '\"')
		SKIN:Bang('!SetOption EventText Hidden 0')
	else
		SKIN:Bang('!SetOption EventText Hidden 1')
	end
end

--Moves the calendar back to the previous month
function PMonth()
	Month = tonumber(mMonth:GetValue())
	Year = tonumber(mYear:GetValue())
	
	if Month > 1 then
		SKIN:Bang("!SetOption mMonth Formula "..Month-1)
		SKIN:Bang("!SetOption mMonthLua Format "..txt_dayA[Month-1])
	else
		SKIN:Bang("!SetOption mMonth Formula "..12)
		SKIN:Bang("!SetOption mMonthLua Format "..txt_dayA[12])
		SKIN:Bang("!SetOption mYear Formula "..Year-1)		
	end
	
	SKIN:Bang("!UpdateMeasure mMonth")
	SKIN:Bang("!UpdateMeasure mYear")		
	SKIN:Bang("!UpdateMeasure mDayCount")
	SKIN:Bang("!Redraw")
	reload = 1
end

--Moves the calendar to the next month
function NMonth()
	Month = tonumber(mMonth:GetValue())
	Year = tonumber(mYear:GetValue())
	
	if Month < 12 then
		SKIN:Bang("!SetOption mMonth Formula "..Month+1)		
		SKIN:Bang("!SetOption mMonthLua Format "..txt_dayA[Month+1])
	else
		SKIN:Bang("!SetOption mMonth Formula "..1)
		SKIN:Bang("!SetOption mMonthLua Format "..txt_dayA[1])
		SKIN:Bang("!SetOption mYear Formula "..Year+1)	
	end
	
	SKIN:Bang("!UpdateMeasure mMonth")
	SKIN:Bang("!UpdateMeasure mYear")
	SKIN:Bang("!UpdateMeasure mDayCount")
	SKIN:Bang("!Redraw")
	reload = 1
end

--Lets you add an event to the calendar by double-clicking on a day
function AddEvent()
	Month = tonumber(mMonth:GetValue())
	Year = tonumber(mYear:GetValue())
	
	Day = SELF:GetOption('Hover')
		
	SKIN:Bang("!execute \[\"\#CURRENTPATH\#\\note.exe\" Eng "..Day.." "..Month.." "..Year.." \"\#CURRENTPATH\#data_B.int\"".." \"\#CURRENTCONFIG\#\" \""..timeMode.."\"\]")	
end
