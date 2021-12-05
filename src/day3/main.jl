# read input
lines = transpose(parse.(Int, hcat(collect.(readlines("input.txt"))...)))

function most_common(M, j)::Int
	rows = size(M, 1)
	num_ones = sum(M[:, j])
	num_zeros = rows - num_ones
	return num_ones >= num_zeros ? 1 : 0
end

# takes the xor of most common array
least_common(M, j) = xor(most_common(M, j), 1)

# calculate gamma and epsilon
cols = size(lines, 2)
gamma = join(string(most_common(lines, j)) for j in 1:cols)
epsilon = join(string(least_common(lines, j)) for j in 1:cols)

# pt.1
@show parse(Int, gamma; base = 2) * parse(Int, epsilon; base = 2)

function slice_by_bit(M, j, bit)
	match_indicies = M[:, j] .== bit
	return M[match_indicies, :]
end

function find_factor(M, algo::Function)
	pos = 1
	while true
		bit = algo(M, pos)
		M = slice_by_bit(M, pos, bit)
		size(M, 1) == 1 && break
		pos += 1
	end
	result = join(string(x) for x in M)
	return result
end

# pt.2
oxygen = find_factor(lines, most_common)
carbon = find_factor(lines, least_common)

@show parse(Int, oxygen; base = 2) * parse(Int, carbon; base = 2)
