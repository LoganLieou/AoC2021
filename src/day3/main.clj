(ns AoC.day3
  (:require
    [clojure.java.io :as io]
    [clojure.string :as str]
    [clojure.set :as set]))

(def input (slurp "input.txt"))

(defn ones? [lines pos]
  (let [chars (map #(nth % pos) lines)
        {zeros \0 ones \1} (frequencies chars)]
    (>= ones zeros)))

(defn invert [digits]
  (mapv #(-1 %) digits))

(defn parse-digits [digits]
  (reduce
    (fn [acc d]
      (+ (bit-shift-left acc 1) d))
    0
    digits))
