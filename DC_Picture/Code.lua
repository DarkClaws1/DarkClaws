function Initialize()
	path = SKIN:GetVariable('path')	
	pics = {}
	
	--Defining the variables for changing
	fileCount = 0
	--How many seconds we wait before changing the picture
	seconds = tonumber(SKIN:GetVariable('seconds'))
	--1 means randomize the picture
	shuffle = tonumber(SKIN:GetVariable('shuffle'))
	--1 means we do not change the photo
	paused = tonumber(SKIN:GetVariable('paused'))
	--1 if our timer is in minutes, --0 if it is in seconds
	timeMode = tonumber(SKIN:GetVariable('timeMode'))
	settings = SKIN:GetVariable('Settings')
	
	if timeMode == 0 then
		SKIN:Bang('!SetOption', 'MeterTimerLabel', 'Text', 'Seconds')
	else
		SKIN:Bang('!SetOption', 'MeterTimerLabel', 'Text', 'Minutes')
	end
	
	SetShuffle()
end

function Calculate()
	mCount = SKIN:GetMeasure('MeasureCount')
	fileCount = tonumber(mCount:GetValue()) 
	
	mName = SKIN:GetMeasure('MeasurePic')
	
	
	for i=1, fileCount do
		pics[i] = 	mName:GetStringValue()	
		SKIN:Bang('!CommandMeasure', 'MeasureFolder', 'PageDown')
	end
	
	--Get the value of current
	current = tonumber(SKIN:GetVariable('current'))	
	
	SetTimer();
		
	Display()	
end

function SetTimer()
	if timeMode == 1 then
		timer = os.clock() + (seconds * 60)
	elseif timeMode == 2 then
		timer = os.clock() + (1 - (0.01 * seconds)) + 0.01
	else
		timer = os.clock() + seconds
	end
	
end


function Update()
	if (fileCount > 0 and seconds > 0 and paused < 1 and os.clock() >= timer) then
		if shuffle > 0 then
			Random()
		else 
			Next()
		end		
	end 	
end


function Next()
	if (shuffle > 0) then
		Random()
	else
		current = current + 1
		Display()
	end
end

function Previous()
	if(shuffle > 0) then
		Random()
	else
		current = current - 1
		Display()
	end
end

function Random()
	rand = math.random(1,fileCount)
	--make sure we do not pick the same number
	while (rand == current) do
		rand = math.random(1,fileCount)
	end
	current = rand
	Display();
end

function ChangePaused()
	paused = (paused + 1) % 2
	SKIN:Bang('!WriteKeyValue', 'Variables', 'paused', paused, settings)
	
	--if paused, show play
	if paused > 0 then 
		SKIN:Bang('!SetOption', 'MeterPlay', 'Text', '4')
	else 
		SKIN:Bang('!SetOption', 'MeterPlay', 'Text', ';')
	end
end



function ChangeShuffle()
	shuffle = (shuffle + 1) % 2
	SKIN:Bang('!WriteKeyValue', 'Variables', 'shuffle', shuffle, settings)
	SetShuffle()
	
end

function SetShuffle()
if shuffle > 0 then
		SKIN:Bang('!SetOption', 'MeterShuffle', 'ImageTint', '#txColor#')
	else 
		SKIN:Bang('!SetOption', 'MeterShuffle', 'ImageTint', '#hlColor#')
	end
end

function Display()
	--Loop around if we reached the end on either side
	if current > fileCount then
		current = 1
	elseif current <= 0 then
		current = fileCount
	end
	
	SKIN:Bang('!WriteKeyValue', 'Variables', 'current', current, settings)
	
	pic = pics[current]
	
	SKIN:Bang('!SetOption', 'MeterPic', 'ImageName', pic)
	
	pathLen = string.len(path)
	picLen = string.len(pic)
	picName = string.sub(pic, pathLen+2, picLen)
	SKIN:Bang('!SetOption', 'MeterPicName', 'Text', picName)
	
	SetTimer()
end

function ChangeFolder(f)
	newPath = SKIN:GetVariable(f)
	SKIN:Bang('!WriteKeyValue', 'Variables', 'path', newPath, settings)
	folder = string.sub(f, 7, -1)
	SKIN:Bang('!WriteKeyValue', 'Variables', 'folder', folder, settings)
	SKIN:Bang('!WriteKeyValue', 'Variables', 'current', 0, settings)
	SKIN:Bang('!Refresh')
end

function FolderUp(f)
	folder = f + 1
	if folder > 10 then
		print(folder)
		folder = 1
	end
	
	ChangeFolder("folder" .. (folder))
end

function FolderDown(f)
	folder = f - 1
	if folder < 1 then
		folder = 10
	end
	
	ChangeFolder("folder" .. (folder))
end

function ChangeTimeMode()
	timeMode = (timeMode + 1) % 2
	SKIN:Bang('!WriteKeyValue', 'Variables', 'timeMode', timeMode, settings)
	if timeMode == 0 then
		SKIN:Bang('!SetOption', 'MeterTimerLabel', 'Text', 'Seconds')
	else
		SKIN:Bang('!SetOption', 'MeterTimerLabel', 'Text', 'Minutes')
	end
end

function ChangeTime(s)
	--clamping
	if (s > 0 and seconds < 10) or (s < 0 and seconds > 1) then	
		seconds = seconds + s
		SKIN:Bang('!WriteKeyValue', 'Variables', 'seconds', seconds, settings)
		SKIN:Bang('!SetOption', 'MeterTimerNumber', 'Text', seconds)
		SetTimer()
	end	
end

function ChangeTimeGIF(s)
	--clamping
	if (s > 0 and seconds < 100) or (s < 0 and seconds > 5) then	
		seconds = seconds + s
		SKIN:Bang('!WriteKeyValue', 'Variables', 'seconds', seconds, settings)
		SKIN:Bang('!SetOption', 'MeterTimerNumber', 'Text', seconds)
		SetTimer()
	end	
	
	-- 1	10
	-- 2	20
	-- 3	30
	-- 4	40
	-- 5	50
	-- 6	60
	-- 7	70
	-- 8	80
	-- 9 	90
	-- 10	100
end