parse_line(x) = let fields = split(x, " ")
	Symbol(fields[1]), parse(Int, fields[2])
end
lines = readlines("input.txt"); lines = parse_line.(lines);

function part1(input)
	pos = 0
	dep = 0
	for (cmd, x) in input
		if cmd == :forward
			pos += x
		elseif cmd == :up
			dep -= x
		elseif cmd == :down
			dep += x
		else
			error("bad input")
		end
	end
	return pos * dep
end

@show part1(lines)

function part2(input)
	pos = dep = aim = 0
	for (cmd, x) in input
		if cmd == :forward
			pos += x
			dep += aim * x
		elseif cmd == :up
			aim -= x
		elseif cmd == :down
			aim += x
		else
			error("bad input!")
		end
	end
	return pos * dep
end

@show part2(lines)
