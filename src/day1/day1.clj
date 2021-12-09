(ns AoC.day1 
  (:require
    [clojure.java.io :as io]
    [clojure.string :as str]
    [clojure.set :as set]))

;; parse a string to long
(defn parse-long [s]
  (Long/valueOf s))

;; get data and process it
(def data
  (with-open [rdr (io/reader (io/file "input.txt"))]
    (->> (line-seq rdr)
         (mapv parse-long))))

;; part 1 solution
(defn part1 []
  ;; positive values indicate that the depth increaced as next > curr
  (->> (map - (next data) data) ; subtract data from next data
       (filter pos?)            ; filter such that only pos values remain
       (count)))                ; return the count of those pos values

;; part 2 solution
(defn part2 []
  ;; a window is the sum of curr data next data nnext data
  (let [windows (map + data (next data) (nnext data))]
  (->> (map - (next windows) windows) ; next windows - windows
       (filter pos?)                  ; filter such that only pos values remain
       (count))))                     ; get the count

(println (part1))
(println (part2))
