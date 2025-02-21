# -- 코드를 작성해주세요
# WITH V AS (
#     SELECT EMP_NO, (CASE WHEN AVG(SCORE) >= 96 THEN 'S' WHEN AVG(SCORE >= 90) THEN 'A' WHEN AVG(SCORE) >= 80 THEN 'B' ELSE 'C' END) AS GRADE
#     FROM HR_GRADE
#     GROUP BY EMP_NO
# )

# SELECT * FROM V;

# # with GRADE as (
# #             select EMP_NO,
# #              (case when avg(SCORE) >= 96 then 'S'
# #                         when avg(SCORE) >= 90 then 'A'
# #                         when avg(SCORE) >= 80 then 'B'
# #                         else 'C' end ) as GRADE,
# #             (case when avg(SCORE) >= 96 then 0.2
# #                                 when avg(SCORE) >= 90 then 0.15
# #                                 when avg(SCORE) >= 80 then 0.1
# #                                 else 0 end ) as BONUS
# #             from HR_GRADE
# #             group by EMP_NO)






WITH V AS (
    SELECT EMP_NO, AVG(SCORE) AS SCORE
    FROM HR_GRADE
    GROUP BY EMP_NO
)


SELECT E.EMP_NO, E.EMP_NAME, CASE WHEN SCORE >= 96 THEN 'S' WHEN SCORE >= 90 THEN 'A' WHEN SCORE >= 80 THEN 'B' ELSE 'C' END AS GRADE, CASE WHEN SCORE >= 96 THEN SAL * 0.2 WHEN SCORE >= 90 THEN SAL * 0.15 WHEN SCORE >= 80 THEN SAL * 0.1 ELSE 0 END AS BONUS
FROM HR_EMPLOYEES E
JOIN V ON E.EMP_NO = V.EMP_NO
ORDER BY E.EMP_NO






