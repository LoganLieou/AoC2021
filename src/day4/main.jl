lines = readlines("input.txt")

moves = parse.(Int, split((filter((s) -> !(s == ""), lines[1:2]))[1], ","))
boards = filter.((s) -> !(s == ""), (split.([l for l in lines[3:end]], " ")))

@show [parse.(Int, board) for board in boards]
