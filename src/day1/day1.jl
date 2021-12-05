# read the input file
lines = readlines("input.txt")

# pt.1
p1(input::Vector{Int64})::Int64 = map((a, b) -> a < b, input, @view(input[2:end])) |> count
@show p1(parse.(Int64, lines))

# pt.2
p2(input::Vector{Int64})::Int64 = map((a, b) -> a < b, input, @view(input[4:end])) |> count
@show p2(parse.(Int64, lines))
