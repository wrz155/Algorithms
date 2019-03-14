int ReadCaseInfo(char *szPath)
{
    if (szPath == NULL)
    {
        return CE_PARAM;
    }
    FILE    *pFile  = fopen(szPath, "r");

    if (pFile == NULL)
    {
        return CE_PARAM;
    }

    fscanf(pFile, "%d %d %d %d",
        &m_nK,
        &m_nP,
        &m_nA,
        &m_nB);
    fscanf(pFile, "%d %d", &m_cGarageMap.m_nRow, &m_cGarageMap.m_nColumn);

    for (int i = 0; i < m_cGarageMap.m_nRow; i++)
    {
        for (int j = 0; j < m_cGarageMap.m_nColumn; j ++)
        {
            char szTmp[2] = {0};
            fscanf(pFile, "%s", szTmp);
            m_cGarageMap.m_cGarageMap[i][j] = szTmp[0];
        }
    }

    // 读取车辆信息
    fscanf(pFile, "%d", &m_cCarGroup.m_nCarNum);
    CCar        cCar;

    for (int i = 0; i < m_cCarGroup.m_nCarNum; i ++)
    {
        fscanf(pFile, "%d %d %d %d %d", 
            &cCar.m_nIndex,
            &cCar.m_nApplyInTime,
            &cCar.m_nApplyOutTime,
            &cCar.m_nMaxWaitTIme,
            &cCar.m_nWeight);
    }

    return CE_SUCCESS;
}