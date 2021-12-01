# read the input file
f = open("input.txt", "r"); input = readlines(f); close(f)

# imperitive solution
function sol(input::Vector{Int64})::Int64
	count = temp = 0
	for i = 2:length(input)
		if temp < input[i]
			count += 1
		end
		temp = input[i]
	end
	return count
end

# functional solution
fsol(input::Vector{Int64})::Int64 = map((a, b) -> a < b, input, @view(input[2:end])) |> count

# omfg I love julia
@show sol(parse.(Int64, input))
@show fsol(parse.(Int64, input))

# part 2 imperitive
"""
damn this shit dumb asf
working on this right now
"""
function sol2(input::Vector{Int64})::Int64
	count = temp = temp_sum = 0
	for i = 4:length(input)
		for j = 1:4
			if input[j] + input[i] > temp
				count += 1
			end
		end
	end
	return count
end

# part 2 functional
fsol2(input::Vector{Int64})::Int64 = map((a, b) -> a < b, input, @view(input[4:end])) |> count

@show fsol2(parse.(Int64, input))
@show sol2(parse.(Int64, input))
