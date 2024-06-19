function Initialize()
	path = SKIN:GetVariable('path')	
	--local lfs = require("lfs")
	--for filename in lfs.dir(path) do
	--		if filename ~= "." and filename ~= ".." then
	--				print("\t" .. filename)
	--		end
	--end
end

function Calculate()
	mCount = SKIN:GetMeasure('MeasureCount')
	print(tonumber(mCount:GetValue()))
end