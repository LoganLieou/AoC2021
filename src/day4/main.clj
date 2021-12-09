(ns advent-of-code-4
  ;; imports
  (:require
    [clojure.java.io :as io]
    [clojure.string :as str]
    [clojure.set :as set]))

;; read in the input
(def input
  (slurp "input.txt"))

;; parse board
(defn parse-board [board]
  (-> board
      (str/trim)
      (str/split #"\s+")
      (->> (mapv parse-long)
         (partition 5)
         (mapv vec)
         (vec))))

;; transpose function
(defn transpose [board]
  (for [col (range (count (first board)))]
    (mapv #(nth % col) board)))

;; parse the input
(defn parse [input]
  (let [[numbers, boards] (str/split input #"\n" 2)]
    {:numbers (-> numbers (str/split #",") (->> (mapv parse-long)))
     :boards  (-> boards (str/split #"\n\n") (->> (mapv parse-board)))}))

(defn score-rows [board nums]
  (let [num-set (set nums)]
    (when (some #(every? num-set %) board)
      (->> board
        (apply concat)
        (remove num-set)
        (reduce +)
        (* (last nums))))))


