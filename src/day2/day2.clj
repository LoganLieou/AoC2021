(ns AoC.day2
  (:require
    [clojure.java.io :as io]
    [clojure.string :as str]
    [clojure.set :as set]))

(defn parse-long [s]
  (Long/valueOf s))

(def data
  (with-open [rdr (io/reader (io/file "input.txt"))]
    (->> (line-seq rdr)
         ;; idk why there's a _ here
         (mapv #(let [[_ cmd arg] (re-matches #"([a-z]+) ([0-9]+)" %)]
                  [(keyword cmd) (parse-long arg)])))))

(defn part1 []
  (let [[x y] (reduce 
                (fn [[x y] [cmd arg]]
                  (case cmd
                    :forward [(+ x arg) y]
                    :down    [x (+ y arg)]
                    :up      [x (- y arg)]))
                [0 0] data)]
    (* x y)))

